#include "edges.h"
#include "common.h"

#include <core/grid.h>
#include <core/utils/helper_math.h>

SdfEdges::SdfEdges(std::vector<real2> edges, bool inside) :
    edges(edges),
    insideSign(inside ? 1 : -1)
{}

static std::vector<real2> convert(std::vector<std::array<real, 2>> src)
{
    std::vector<real2> dst;
    for (const auto& r : src)
        dst.push_back({r[0], r[1]});
    return dst;
}

SdfEdges::SdfEdges(std::vector<std::array<real, 2>> edges, bool inside) :
    SdfEdges(convert(edges), inside)
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

real SdfEdges::at(real3 pos) const
{
    int count = 0;
    real mind = 1e9;

    // TODO: for now assume xy plane
    real2 r = {pos.x, pos.y};
    real2 orig = {0.25f, 0.33f}; // TODO no hardcoded, choose a suitable point
    
    for (int i = 0; i < edges.size(); ++i) {

        int inext = (i+1) % edges.size();
        auto a = edges[i    ];
        auto b = edges[inext];
        
        mind = std::min(mind, distanceToEdge(r, a, b));
        count += insideTriangle(r, orig, a, b);
    }
    int sign = (count % 2) ? -1 : 1;
    return mind * sign * insideSign;
}

#define CLASS_NAME SdfEdges
GENERATE_IMPL_OPERATIONS()
