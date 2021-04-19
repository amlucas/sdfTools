#! /usr/bin/env python

import numpy as np
import sdf_tools

n = 8

offs = (0., 0., 0.)
dims = (n, n, 1)
exts = (1.0, 1.0, 0.0)
center = (0.5, 0.5, 0.0)
radius = 0.4

grid = sdf_tools.Grid.Uniform(dims, offs, exts)

sphere = sdf_tools.Sdf.Sphere(center, radius, inside=True)

grid.applySdf(sphere)

np.savetxt("grid.txt", grid.get())

# TEST: analytical.2d
# cd analytical
# rm -rf *.txt
# ./2d.py
# mv grid.txt grid.out.txt
