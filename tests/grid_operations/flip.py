#! /usr/bin/env python

import numpy as np
import sdfTools

n0 = 32

offs = (0., 0., 0.)
dims = (n0, 3*n, 2*n)
exts = (1.0, 3.0, 2.0)

center = (0.35, 0.75, 0.5)
radius = 0.2

grid = sdfTools.Grid.Uniform(dims, offs, exts)

sphere = sdfTools.Sdf.Sphere(center, radius, inside=True)

sphere.apply(grid)

grid.flip('xyz')

grid.dumpBov("sphere");

np.savetxt("grid.txt", grid1.get())

# TEST: grid_operations.flip.xyz
# cd grid_operations
# rm -rf *.txt
# ./flip.py
# mv grid.txt grid.out.txt

