#! /usr/bin/env python

import numpy as np
import sdfTools

n = 5

offs = (0., 0., 0.)
dims = (n, n, n)
exts = (1.0, 1.0, 1.0)

center1 = (0.35, 0.5, 0.5)
radius1 = 0.3
center2 = (0.55, 0.5, 0.5)
radius2 = 0.4

grid = sdfTools.Grid.Uniform(dims, offs, exts)

sphere1 = sdfTools.Sdf.Sphere(center1, radius1, inside=True)
sphere2 = sdfTools.Sdf.Sphere(center2, radius2, inside=True)

sphere1.apply(grid)
sphere2.interiorUnion(grid)

np.savetxt("grid.txt", grid.get())

# TEST: operations.union
# cd operations
# rm -rf *.txt
# ./union.py
# mv grid.txt grid.out.txt

