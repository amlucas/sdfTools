#pragma once

#include "interface.h"
#include "operations.h"

#include <core/grid.h>
#include <core/utils/helper_math.h>

template <class SDF>
class SdfImpl : public Sdf
{
public:
    SdfImpl() = default;
    ~SdfImpl() = default;

    void apply(Grid *grid) const override
    {
        applyOperation(grid, SdfOperation::Identity{});
    }
    
    void applyComplement (Grid *grid) const override
    {
        applyOperation(grid, SdfOperation::Complement{});
    }

    void interiorUnion(Grid *grid) const
    {
        applyOperation(grid, SdfOperation::Union{});
    }
    
    void interiorIntersection(Grid *grid) const
    {
        applyOperation(grid, SdfOperation::Intersection{});
    }

    void interiorSubtractToGrid(Grid *grid) const
    {
        applyOperation(grid, SdfOperation::SubtractToGrid{});
    }
    
    void interiorSubtractGrid(Grid *grid) const
    {
        applyOperation(grid, SdfOperation::SubtractGrid{});
    }

    
    void applyPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(grid, SdfOperation::Identity{});
    }
    
    void applyComplementPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(grid, SdfOperation::Complement{});
    }

    void interiorUnionPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(grid, SdfOperation::Union{});
    }
    
    void interiorIntersectionPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(grid, SdfOperation::Intersection{});
    }

    void interiorSubtractToGridPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(grid, SdfOperation::SubtractToGrid{});
    }
    
    void interiorSubtractGridPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(grid, SdfOperation::SubtractGrid{});
    }

protected:

    template <typename Op>
    void applyOperation(Grid *grid, Op op) const
    {
        const auto self = static_cast<const SDF*>(this);
            
        auto dims = grid->getDimensions();
        auto exts = grid->getExtents();
        auto offs = grid->getOffsets();
        real *data = grid->data();
        
        const real3 d = exts / dims;
        
        for (int iz = 0; iz < dims.z; ++iz)
            for (int iy = 0; iy < dims.y; ++iy)
                for (int ix = 0; ix < dims.x; ++ix) {
                    real3 r;
                    r.x = offs.x + ix * d.x;
                    r.y = offs.y + iy * d.y;
                    r.z = offs.z + iz * d.z;
                    
                    const int i = ix + dims.x * (iy + dims.y * iz);
                    
                    data[i] = op(self->at(r), data[i]);
                }    
    }

    template <typename Op>
    void applyOperationPeriodic(Grid *grid, Op op) const
    {
        const auto self = static_cast<const SDF*>(this);
        
        const auto dims = grid->getDimensions();
        const auto exts = grid->getExtents();
        const auto offs = grid->getOffsets();
        real *data = grid->data();

        const real3 d = exts / dims;

        for (int iz = 0; iz < dims.z; ++iz) {
            for (int iy = 0; iy < dims.y; ++iy) {
                for (int ix = 0; ix < dims.x; ++ix) {
                    const real3 r0 {offs.x + ix * d.x,
                                    offs.y + iy * d.y,
                                    offs.z + iz * d.z};

                    const int i = ix + dims.x * (iy + dims.y * iz);

                    auto val = self->at(r0);
                    
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
                                
                                val = SdfOperation::Union{}(self->at(r), val);
                            }
                        }
                    }
                    data[i] = op(val, data[i]);
                }
            }
        }
    }
};
