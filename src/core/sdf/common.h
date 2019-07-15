#include <core/grid.h>
#include <core/utils/helper_math.h>

namespace common
{    
template <typename SDF, typename Op>
inline void applyOperation(const SDF *sdf, Grid *grid, Op op)
{
    auto dims = grid->getDimensions();
    auto exts = grid->getExtents();
    auto offs = grid->getOffsets();
    real *data = grid->data();

    real3 d = exts / dims;

    for (int iz = 0; iz < dims.z; ++iz)
        for (int iy = 0; iy < dims.y; ++iy)
            for (int ix = 0; ix < dims.x; ++ix) {
                real3 r;
                r.x = offs.x + ix * d.x;
                r.y = offs.y + iy * d.y;
                r.z = offs.z + iz * d.z;

                const int i = ix + dims.x * (iy + dims.y * iz);
                    
                data[i] = op(sdf->at(r), data[i]);
            }    
}

template <typename SDF, typename Op0, typename OpP>
void applyOperationPeriodic(const SDF *sdf, Grid *grid, Op0 opInit, OpP opPeriodic)
{
    auto dims = grid->getDimensions();
    auto exts = grid->getExtents();
    auto offs = grid->getOffsets();
    real *data = grid->data();

    real3 d = exts / dims;

    for (int iz = 0; iz < dims.z; ++iz) {
        for (int iy = 0; iy < dims.y; ++iy) {
            for (int ix = 0; ix < dims.x; ++ix) {
                const real3 r0 {offs.x + ix * d.x,
                                offs.y + iy * d.y,
                                offs.z + iz * d.z};

                const int i = ix + dims.x * (iy + dims.y * iz);

                auto val = opInit(sdf->at(r0), data[i]);
                    
                for (int dirz = -1; dirz < 2; ++dirz) {
                    for (int diry = -1; diry < 2; ++diry) {
                        for (int dirx = -1; dirx < 2; ++dirx) {
                            if (dirz == 0 &&
                                diry == 0 &&
                                dirx == 0)
                                continue;
                                
                            auto r = r0;
                            r.x += dirx * exts.x;
                            r.y += diry * exts.y;
                            r.z += dirz * exts.z;
                                
                            val = opPeriodic(sdf->at(r), val);
                        }
                    }
                }
                data[i] = val;
            }
        }
    }
}


template <typename SDF>
void apply(const SDF *sdf, Grid *grid)
{
    applyOperation(sdf, grid, [](real s, real g){return s;});
}

template <typename SDF>
void applyPeriodic(const SDF *sdf, Grid *grid)
{
    applyOperationPeriodic(sdf, grid,
                           [](real s, real g){return s;},
                           [](real s, real g){return std::min(s, g);});
}

template <typename SDF>
void applyComplement(const SDF *sdf, Grid *grid)
{
    applyOperation(sdf, grid, [](real s, real g){return -s;});
}

template <typename SDF>
void interiorUnion(const SDF *sdf, Grid *grid)
{
    applyOperation(sdf, grid, [](real s, real g){return std::min(s, g);});
}

template <typename SDF>
void interiorIntersection(const SDF *sdf, Grid *grid)
{
    applyOperation(sdf, grid, [](real s, real g){return std::max(s, g);});
}

template <typename SDF>
void interiorSubtractToGrid(const SDF *sdf, Grid *grid)
{
    applyOperation(sdf, grid, [](real s, real g){return std::max(-s, g);});
}

template <typename SDF>
void interiorSubtractGrid(const SDF *sdf, Grid *grid)
{
    applyOperation(sdf, grid, [](real s, real g){return std::max(s, -g);});
}
}
