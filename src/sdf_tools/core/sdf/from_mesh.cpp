#include "from_mesh.h"

#include <sdf_tools/core/utils/helper_math.h>

#include <vector>

namespace sdf_tools {
namespace sdf {

SdfFromMesh::SdfFromMesh(std::vector<int3> faces, std::vector<real3> vertices, bool inside) :
    faces_(std::move(faces)),
    vertices_(std::move(vertices)),
    sign_(inside ? 1 : -1)
{}



static inline real3 getBarycentricCoords(real3 p, real3 a, real3 b, real3 c)
{
    const real3 v0 = b - a, v1 = c - a, v2 = p - a;
    const real d00 = dot(v0, v0);
    const real d01 = dot(v0, v1);
    const real d11 = dot(v1, v1);
    const real d20 = dot(v2, v0);
    const real d21 = dot(v2, v1);
    const real denom = d00 * d11 - d01 * d01;

    const real v = (d11 * d20 - d01 * d21) / denom;
    const real w = (d00 * d21 - d01 * d20) / denom;
    const real u = 1.0_r - v - w;

    return {u, v, w};
}

static inline real distanceToTriangle(real3 r, real3 a, real3 b, real3 c)
{
    // 1. project in 2D plane containing the triangle
    const real3 ac = c - a;
    const real3 ab = b - a;
    const real3 ar = r - a;
    const real3 n = cross(ab, ac);

    const real alpha = dot(ar, n) / dot(n, n);
    const real3 rp = r - alpha * n;

    // 2. compute the barycentric coordinates
    const real3 bar = getBarycentricCoords(rp, a, b, c);

    // 3. project on the triangle in barycentric coordinates space
    real3 barp {std::max(0.0_r, bar.x),
                std::max(0.0_r, bar.y),
                std::max(0.0_r, bar.z)};
    barp /= (barp.x + barp.y + barp.z);

    // 4. reconstruct the projected point in real space
    const real3 rpt = barp.x * a + barp.y * b + barp.z * c;

    // 5. return the distance
    return length(r - rpt);
}

static real computeDistanceToMesh(real3 r,
                                  const std::vector<int3>& faces,
                                  const std::vector<real3>& vertices)
{
    real distance = length(r - vertices[0]);
    for (const int3 t : faces)
    {
        const real3 a = vertices[t.x];
        const real3 b = vertices[t.y];
        const real3 c = vertices[t.z];

        distance = std::min(distance, distanceToTriangle(r, a, b, c));
    }
    return distance;
}

static inline bool areSameSideOfTriangle(real3 r, real3 q, real3 a, real3 b, real3 c)
{
    const real3 n = cross(b-a, c-a);
    return dot(r - a, n) * dot(q - a, n) >= 0;
}

static inline bool insideTetrahedron(real3 r, real3 a, real3 b, real3 c, real3 d)
{
    return
        areSameSideOfTriangle(r, a,  b, c, d) &&
        areSameSideOfTriangle(r, b,  c, d, a) &&
        areSameSideOfTriangle(r, c,  d, a, b) &&
        areSameSideOfTriangle(r, d,  a, b, c);
}

static bool isInsideMesh(real3 r,
                         const std::vector<int3>& faces,
                         const std::vector<real3>& vertices,
                         real3 origin)
{
    int counts = 0;
    for (const int3 t : faces)
    {
        const real3 a = vertices[t.x];
        const real3 b = vertices[t.y];
        const real3 c = vertices[t.z];

        if (insideTetrahedron(r,  a, b, c, origin))
            ++counts;
    }
    return (counts % 2) == 0;
}

real SdfFromMesh::at(real3 r) const
{
    const real distance = computeDistanceToMesh(r, faces_, vertices_);

    // test on "random" origins and vote.
    constexpr int n = 5;
    const real3 origins[n] = {real3{0.0235_r, 0.045632_r, 0.23440_r},
                              real3{0.1928_r, 0.009273_r, 0.45640_r},
                              real3{0.1209_r, 0.186098_r, 0.03464_r},
                              real3{0.1409_r, 0.986990_r, 0.43556_r},
                              real3{0.1293_r, 0.108780_r, 0.67470_r}};
    int nInside = 0;
    for (int i = 0; i < n; ++i)
    {
        if (isInsideMesh(r, faces_, vertices_, origins[i]))
            ++nInside;
    }

    const int sign = (nInside > n/2) ? sign_ : -sign_;

    return sign * distance;
}

} // namespace sdf
} // namespace sdf_tools
