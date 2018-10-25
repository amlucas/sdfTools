#pragma once

class Grid;

void gridSdfComplement(Grid *grid);
void gridSdfInteriorUnion(Grid *grid1, const Grid *grid2);
void gridSdfInteriorIntersection(Grid *grid1, const Grid *grid2);
void gridSdfSubtract(Grid *grid1, const Grid *grid2);
