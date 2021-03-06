#include "edges.h"

#include <sdf_tools/core/utils/helper_math.h>

namespace sdf_tools {
namespace sdf {

SdfEdges::SdfEdges(std::vector<real2> edges, bool inside, int nsamples) :
    edges_(std::move(edges)),
    insideSign_(inside ? 1 : -1),
    nsamples_(nsamples)
{
    origin_ = findOrigin_();
}

static inline real distanceToEdge(real2 r, real2 a, real2 b)
{
    const real2 ab = b - a;
    const real2 ar = r - a;
    const real ab_length = length(ab);
    real alpha = dot(ab, ar) / ab_length;

    alpha = std::max((real) 0, std::min(ab_length, alpha));

    const real2 p = a + (alpha / ab_length) * ab;
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

static inline real distanceToEdges(const std::vector<real2>& edges, real2 r)
{
    real mind = 1e9;

    for (size_t i = 0; i < edges.size(); ++i)
    {
        const size_t inext = (i+1) % edges.size();
        const real2 a = edges[i    ];
        const real2 b = edges[inext];

        mind = std::min(mind, distanceToEdge(r, a, b));
    }
    return mind;
}

static inline std::vector<real2> generateSamples(real2 r, real d, int nsamples, std::mt19937& gen)
{
    std::vector<real2> samples;
    samples.reserve(nsamples);
    std::uniform_real_distribution<real> distTheta(0.0_r, 2.0_r * M_PI);
    std::uniform_real_distribution<real> distRho(0.0_r, d*d);

    for (int i = 0; i < nsamples; ++i)
    {
        const real theta = distTheta(gen);
        const real rho   = std::sqrt(distRho(gen));
        const real2 pos {r.x + rho * std::cos(theta),
                         r.y + rho * std::sin(theta)};
        samples.push_back(pos);
    }
    return samples;
}

static inline int getSignMC(const std::vector<int>& counts)
{
    int sum = 0;
    for (auto c : counts)
        sum += (c % 2) ? -1 : 1;
    return (sum >= 0) ? 1 : -1;
}

static inline int getSignInsideEdges(const std::vector<real2>& edges, real distance,
                                     real2 r, real2 origin, int nSamples, std::mt19937& gen)
{
    constexpr real delta = 1e-2_r;
    const auto samples = generateSamples(r, distance * delta, nSamples, gen);

    std::vector<int> counts(nSamples, 0);

    for (size_t i = 0; i < edges.size(); ++i)
    {
        const size_t inext = (i+1) % edges.size();
        const real2 a = edges[i    ];
        const real2 b = edges[inext];

        for (int j = 0; j < nSamples; ++j)
            counts[j] += insideTriangle(samples[j], origin, a, b);
    }
    return getSignMC(counts);
}

real SdfEdges::at(real3 pos) const
{
    // TODO: for now assume xy plane
    const real2 r = {pos.x, pos.y};

    const real distance = distanceToEdges(edges_, r);
    const int sign = getSignInsideEdges(edges_, distance, r, origin_, nsamples_, gen_);
    return distance * sign * insideSign_;
}

static inline bool areColinear(real2 a, real2 b, real2 r, real tolerance)
{
    const real2 ab = b - a;
    const real2 ar = r - a;
    const real ab_length = length(ab);
    const real alpha = dot(ab, ar) / ab_length;
    const real2 p = a + (alpha / ab_length) * ab;
    return length(r - p) < tolerance;
}

static inline bool isColinearWithAnyEdge(const std::vector<real2>& edges, const real2 origin, real tolerance)
{
    for (size_t i = 0; i < edges.size(); ++i)
    {
        const size_t inext = (i+1) % edges.size();
        const real2 a = edges[i    ];
        const real2 b = edges[inext];

        if (areColinear(a, b, origin, tolerance))
            return true;
    }
    return false;
}

real2 SdfEdges::findOrigin_()
{
    constexpr real tolerance = 1e-3_r;

    auto generateRandomReal2 = [](std::mt19937& gen)
    {
        std::uniform_real_distribution<real> dist(-10.0, 10.0);
        real2 r;
        r.x = dist(gen);
        r.y = dist(gen);
        return r;
    };

    real2 r;
    do
    {
        r = generateRandomReal2(gen_);
    } while (isColinearWithAnyEdge(edges_, origin_, tolerance));

    return r;
}

} // namespace sdf
} // namespace sdf_tools
