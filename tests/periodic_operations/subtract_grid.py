#! /usr/bin/env python

import numpy as np
import sdf_tools

n = 5

offs = (0., 0., 0.)
dims = (n, n, n)
exts = (1.0, 1.0, 1.0)

center1 = (0.75, 0.5, 0.5)
radius1 = 0.3
center2 = (0.95, 0.5, 0.5)
radius2 = 0.4

grid = sdf_tools.Grid.Uniform(dims, offs, exts)

sphere1 = sdf_tools.Sdf.Sphere(center1, radius1, inside=True)
sphere2 = sdf_tools.Sdf.Sphere(center2, radius2, inside=True)

sphere1.applyPeriodic(grid)
sphere2.interiorSubtractGridPeriodic(grid)

np.savetxt("grid.txt", grid.get())

# TEST: periodic_operations.subtract_grid
# cd periodic_operations
# rm -rf *.txt
# ./subtract_grid.py
# mv grid.txt grid.out.txt
