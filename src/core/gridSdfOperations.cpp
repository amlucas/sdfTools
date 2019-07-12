#include "gridSdfOperations.h"

#include <core/grid.h>

template <typename Op>
inline void applyOperation(Grid *grid, Op op)
{
    auto dims = grid->getDimensions();
    real *data = grid->data();

    for (int iz = 0; iz < dims.z; ++iz)
        for (int iy = 0; iy < dims.y; ++iy)
            for (int ix = 0; ix < dims.x; ++ix) {
                const int i = ix + dims.x * (iy + dims.y * iz);                    
                data[i] = op(data[i]);
            }    
}

void gridSdfComplement(Grid *grid)
{
    applyOperation(grid, [](real a){return -a;});
}

template <typename Op>
inline void applyBinaryOperation(Grid *grid1, const Grid *grid2, Op op)
{
    auto dims = grid1->getDimensions();
    real *data1 = grid1->data();
    const real *data2 = grid2->data();

    for (int iz = 0; iz < dims.z; ++iz)
        for (int iy = 0; iy < dims.y; ++iy)
            for (int ix = 0; ix < dims.x; ++ix) {
                const int i = ix + dims.x * (iy + dims.y * iz);
                data1[i] = op(data1[i], data2[i]);
            }    
}

void gridSdfInteriorUnion(Grid *grid1, const Grid *grid2)
{
    applyBinaryOperation(grid1, grid2, [](real a, real b){return std::max(a, b);});
}

void gridSdfInteriorIntersection(Grid *grid1, const Grid *grid2)
{
    applyBinaryOperation(grid1, grid2, [](real a, real b){return std::min(a, b);});
}

void gridSdfSubtract(Grid *grid1, const Grid *grid2)
{
    applyBinaryOperation(grid1, grid2, [](real a, real b){return std::max(a, -b);});
}
