#include "edges.h"

#include <core/grid.h>
#include <core/utils/helper_math.h>

SdfEdges::SdfEdges(const std::vector<real2>& edges, bool inside, int nsamples) :
    edges(edges),
    insideSign(inside ? 1 : -1),
    nsamples(nsamples)
{}

static std::vector<real2> convert(const std::vector<std::array<real, 2>>& src)
{
    std::vector<real2> dst;
    for (const auto& r : src)
        dst.push_back({r[0], r[1]});
    return dst;
}

SdfEdges::SdfEdges(const std::vector<std::array<real, 2>>& edges, bool inside, int nsamples) :
    SdfEdges(convert(edges), inside, nsamples)
{}
    

static inline real distanceToEdge(real2 r, real2 a, real2 b)
{
    real2 ab = b - a;
    real2 ar = r - a;
    real ab_length = length(ab);
    real alpha = dot(ab, ar) / ab_length;

    alpha = std::max((real) 0, std::min(ab_length, alpha));
    
    real2 p = a + (alpha / ab_length) * ab;
    return length(r - p);
}

static inline int sameSideOfEdge(real2 r1, real2 r2, real2 a, real2 b)
{
    real2 ab = b - a;
    int sign = ab.y > 0 ? 1 : -1;
    real2  n = {sign * ab.y, -sign * ab.x};
    real2 ar1 = r1 - a;
    real2 ar2 = r2 - a;
    return dot(ar1, n) * dot(ar2, n) > 0;
}

static inline int insideTriangle(real2 r, real2 a, real2 b, real2 c)
{
    return
        sameSideOfEdge(r, c, a, b) &&
        sameSideOfEdge(r, a, b, c) &&
        sameSideOfEdge(r, b, c, a);
}

static inline std::vector<real2> generateOrigin(int nsamples, std::mt19937& gen)
{
    std::vector<real2> origins;
    origins.reserve(nsamples);
    std::uniform_real_distribution<real> dist(-1.0, 1.0);

    for (int i = 0; i < nsamples; ++i)
    {
        real2 r;
        r.x = dist(gen);
        r.y = dist(gen);
        origins.push_back(r);
    }
    return origins;
}

static inline int getSignMC(const std::vector<int>& counts)
{
    int sumSigns = 0;

    for (auto c : counts)
        sumSigns += (c % 2) ? -1 : 1;
    
    return (sumSigns >= 0) ? 1 : -1;
}

real SdfEdges::at(real3 pos) const
{
    std::vector<int> counts(nsamples, 0);
    real mind = 1e9;

    // TODO: for now assume xy plane
    const real2 r = {pos.x, pos.y};
    const auto origins = generateOrigin(nsamples, gen);

    for (size_t i = 0; i < edges.size(); ++i)
    {
        const size_t inext = (i+1) % edges.size();
        const real2 a = edges[i    ];
        const real2 b = edges[inext];
        
        mind = std::min(mind, distanceToEdge(r, a, b));

        for (int j = 0; j < nsamples; ++j)
            counts[j] += insideTriangle(r, origins[j], a, b);
    }
    const int sign = getSignMC(counts);
    return mind * sign * insideSign;
}
