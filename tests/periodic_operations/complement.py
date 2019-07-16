#! /usr/bin/env python

import numpy as np
import sdfTools

n = 5

offs = (0., 0., 0.)
dims = (n, n, n)
exts = (1.0, 1.0, 1.0)

center = (0.35, 0.5, 0.5)
radius = 0.3

grid = sdfTools.Grid.Uniform(dims, offs, exts)

sphere = sdfTools.Sdf.Sphere(center, radius, inside=True)

sphere.applyComplementPeriodic(grid)
grid.applySdfComplement()

np.savetxt("grid.txt", grid.get())

# TEST: periodic_operations.complement
# cd periodic_operations
# rm -rf *.txt
# ./complement.py
# mv grid.txt grid.out.txt

