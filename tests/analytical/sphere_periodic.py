#! /usr/bin/env python

import numpy as np
import sdf_tools

n = 5

offs = (0., 0., 0.)
dims = (n, n, n)
exts = (1.0, 1.0, 1.0)
center = (0.0, 0., 0.5)
radius = 0.4

grid = sdf_tools.Grid.Uniform(dims, offs, exts)

sphere = sdf_tools.Sdf.Sphere(center, radius, inside=True)

grid.applySdfPeriodic(sphere)

np.savetxt("grid.txt", grid.get())

# TEST: analytical.sphere_periodic
# cd analytical
# rm -rf *.txt
# ./sphere_periodic.py
# mv grid.txt grid.out.txt
