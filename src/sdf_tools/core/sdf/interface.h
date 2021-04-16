#pragma once

namespace sdf_tools {

class Grid;

namespace sdf {

class Sdf
{
public:

    Sdf() = default;
    virtual ~Sdf() = default;

    virtual void apply           (Grid *grid) const = 0;
    virtual void applyComplement (Grid *grid) const = 0;

    virtual void interiorUnion        (Grid *grid) const = 0;
    virtual void interiorIntersection (Grid *grid) const = 0;

    virtual void interiorSubtractToGrid (Grid *grid) const = 0;
    virtual void interiorSubtractGrid   (Grid *grid) const = 0;


    virtual void applyPeriodic           (Grid *grid) const = 0;
    virtual void applyComplementPeriodic (Grid *grid) const = 0;

    virtual void interiorUnionPeriodic        (Grid *grid) const = 0;
    virtual void interiorIntersectionPeriodic (Grid *grid) const = 0;

    virtual void interiorSubtractToGridPeriodic (Grid *grid) const = 0;
    virtual void interiorSubtractGridPeriodic   (Grid *grid) const = 0;
};

} // namespace sdf
} // namespace sdf_tools
