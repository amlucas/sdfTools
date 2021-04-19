#! /usr/bin/env python

import sdf_tools
import sdf_tools.Sdf as sdf
import numpy as np


offs = [0., 0., 0.]
dims = [128, 64, 64]
exts = [2.0, 1.0, 1.0]

grid = sdf_tools.Grid.Uniform(dims, offs, exts)

edges = [[0.1, 0.1],
         [0.1, 0.9],
         [1.9, 0.5]]

triangle_prism = sdf.Edges(edges, inside=True)
plate_hi = sdf.Plate(point  = [0, 0, 0.1*exts[2]], normal = [0, 0, +1])
plate_lo = sdf.Plate(point  = [0, 0, 0.9*exts[2]], normal = [0, 0, -1])

my_sdf = sdf.Difference(triangle_prism, sdf.Union(plate_lo, plate_hi))

for i in range(50):
    radius = np.random.uniform(0.02, 0.12)
    center = np.random.uniform(offs, exts)
    sphere = sdf.Sphere(center.tolist(), radius, inside=True)
    my_sdf = sdf.Difference(my_sdf, sphere)

grid.applySdf(my_sdf)
grid.dumpBov("cheese")
