#include "edges.h"
#include "core/utils/helper_math.h"

#include "common.h"

SdfEdges::SdfEdges(std::vector<real2> edges) :
    edges(edges)
{}

SdfEdges::SdfEdges(std::vector<std::array<real, 2>> edges)
{
    for (const auto& r : edges)
        this->edges.push_back({r[0], r[1]});
}
    

static inline real distanceToEdge(real2 r, real2 a, real2 b)
{
    real2 ab = b - a;
    real2 ar = r - a;
    real alpha = dot(ab, ar) / length(ab);

    alpha = std::min((real) 0, std::max((real) 1, alpha));
    
    real2 p = a + alpha * ab;
    return length(r - p);
}

static inline int sideOfEdge(real2 r, real2 a, real2 b)
{
    real2 ab = b - a;
    real2 ar = r - a;
    return ab.y * ar.x - ab.x * ar.y > 0;
}

real SdfEdges::at(real3 pos) const
{
    int count = 0;
    real mind = 1e9;

    // TODO: for now assume xy plane
    real2 r = {pos.x, pos.y};
    
    for (int i = 0; i < edges.size(); ++i) {

        int inext = (i+1) % edges.size();
        auto a = edges[i    ];
        auto b = edges[inext];
        
        mind = std::min(mind, distanceToEdge(r, a, b));
        count += sideOfEdge(r, a, b);
    }
    int sign = (count % 2) ? 1 : -1;
    return mind * sign;
}

#define CLASS_NAME SdfEdges
GENERATE_IMPL_OPERATIONS()
