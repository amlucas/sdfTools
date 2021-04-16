#! /usr/bin/env python

import sdf_tools

offs = (0., 0., 0.)
dims = (64, 64, 1)
exts = (1.0, 1.0, 0.0)

grid = sdf_tools.Grid.Uniform(dims, offs, exts)

#create a triangle
edges = [[0.1, 0.1],
         [0.9, 0.1],
         [0.5, 0.9]]

triangle = sdf_tools.Sdf.Edges(edges, inside=True)

triangle.apply(grid)

# extrude the triangle to get a pillar shape
grid.extrude(offs[2], 2.0, 64)

# we can then apply further operations; here we subtract a sphere
sphere = sdf_tools.Sdf.Sphere(center=(0.5, 0.5, 0.5),
                              radius=0.4, inside=True)

sphere.interiorSubtractToGrid(grid)

grid.dumpBov("prism")
