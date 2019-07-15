#pragma once

class Grid;

class Sdf
{
public:

    Sdf();
    virtual ~Sdf();

    virtual void apply           (Grid *grid) const = 0;
    virtual void applyComplement (Grid *grid) const = 0;

    virtual void interiorUnion        (Grid *grid) const = 0;
    virtual void interiorIntersection (Grid *grid) const = 0;

    virtual void interiorSubtractToGrid (Grid *grid) const = 0;
    virtual void interiorSubtractGrid   (Grid *grid) const = 0;

    
    virtual void applyPeriodic           (Grid *grid) const = 0;
    virtual void applyComplementPeriodic (Grid *grid) const = 0;
};
