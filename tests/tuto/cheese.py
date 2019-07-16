#! /usr/bin/env python

import sdfTools
import numpy as np

offs = [0., 0., 0.]
dims = [128, 64, 1]
exts = [2.0, 1.0, 0.0]

grid = sdfTools.Grid.Uniform(dims, offs, exts)

edges = [[0.1, 0.1],
         [0.1, 0.9],
         [1.9, 0.5]]

triangle = sdfTools.Sdf.Edges(edges, inside=True)
triangle.apply(grid)

dims[2] = 64
exts[2] = 1.0
grid.extrude(offs[2], exts[2], dims[2])

sdfTools.Sdf.Plate(point  = [0, 0, 0.1*exts[2]],
                   normal = [ 0, 0, 1]).interiorIntersection(grid)

sdfTools.Sdf.Plate(point  = [0, 0, 0.9*exts[2]],
                   normal = [0, 0, -1]).interiorIntersection(grid)

for i in range(50):
    radius = np.random.uniform(0.02, 0.12)
    center = np.random.uniform(offs, exts)
    sphere = sdfTools.Sdf.Sphere(center, radius, inside=True)
    sphere.interiorSubtractToGrid(grid)

grid.dumpBov("cheese")
