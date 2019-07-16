#! /usr/bin/env python

import sdfTools

offs = (0., 0., 0.)
dims = (64, 64, 1)
exts = (1.0, 1.0, 0.0)

grid = sdfTools.Grid.Uniform(dims, offs, exts)

#create a triangle
edges = [[0.1, 0.1],
         [0.9, 0.1],
         [0.5, 0.9]]

triangle = sdfTools.Sdf.Edges(edges, inside=True)

triangle.apply(grid)

# extrude the triangle to get a pillar shape
grid.extrude(offs[2], 2.0, 64)

# we can then apply further operations; here we subtract a sphere
sphere = sdfTools.Sdf.Sphere(center=(0.5, 0.5, 0.5),
                             radius=0.4, inside=True)

sphere.interiorSubtractToGrid(grid)

grid.dumpBov("prism")
