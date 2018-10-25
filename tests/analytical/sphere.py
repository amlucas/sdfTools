#! /usr/bin/env python

import numpy as np
import sdfTools

n = 5

offs = (0., 0., 0.)
dims = (n, n, n)
exts = (1.0, 1.0, 1.0)
center = (0.5, 0.5, 0.5)
radius = 0.4

grid = sdfTools.Grid.Uniform(dims, offs, exts)

sphere = sdfTools.Sdf.Sphere(center, radius, inside=True)

sphere.apply(grid)

np.savetxt("grid.txt", grid.get())

# TEST: analytical.sphere
# cd analytical
# rm -rf *.txt
# ./sphere.py
# mv grid.txt grid.out.txt

