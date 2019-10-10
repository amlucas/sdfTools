#pragma once

#include "interface.h"
#include "operations.h"

#include <core/grid.h>
#include <core/utils/helper_math.h>


template <typename SDF, typename Op>
static inline void applyOperation(const SDF *sdf, Grid *grid, Op op)
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

template <typename SDF, typename Op>
static inline void applyOperationPeriodic(const SDF *sdf, Grid *grid, Op op)
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

                auto val = sdf->at(r0);
                    
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
                                
                            val = SdfOperation::Union{}(sdf->at(r), val);
                        }
                    }
                }
                data[i] = op(val, data[i]);
            }
        }
    }
}

template <class SDF>
class SdfImpl : public Sdf
{
public:
    SdfImpl() = default;
    ~SdfImpl() = default;

    const SDF* self() const
    {
        return static_cast<const SDF*>(this);
    }
    
    void apply(Grid *grid) const override
    {
        applyOperation(self(), grid, SdfOperation::Identity{});
    }
    
    void applyComplement (Grid *grid) const override
    {
        applyOperation(self(), grid, SdfOperation::Complement{});
    }

    void interiorUnion(Grid *grid) const
    {
        applyOperation(self(), grid, SdfOperation::Union{});
    }
    
    void interiorIntersection(Grid *grid) const
    {
        applyOperation(self(), grid, SdfOperation::Intersection{});
    }

    void interiorSubtractToGrid(Grid *grid) const
    {
        applyOperation(self(), grid, SdfOperation::SubtractToGrid{});
    }
    
    void interiorSubtractGrid(Grid *grid) const
    {
        applyOperation(self(), grid, SdfOperation::SubtractGrid{});
    }

    
    void applyPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(self(), grid, SdfOperation::Identity{});
    }
    
    void applyComplementPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(self(), grid, SdfOperation::Complement{});
    }

    void interiorUnionPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(self(), grid, SdfOperation::Union{});
    }
    
    void interiorIntersectionPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(self(), grid, SdfOperation::Intersection{});
    }

    void interiorSubtractToGridPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(self(), grid, SdfOperation::SubtractToGrid{});
    }
    
    void interiorSubtractGridPeriodic(Grid *grid) const
    {
        applyOperationPeriodic(self(), grid, SdfOperation::SubtractGrid{});
    }
};
