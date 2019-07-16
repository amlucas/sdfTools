#! /usr/bin/env python

import sdfTools

offs = (0., 0., 0.)
dims = (128, 64, 64)
exts = (2.0, 1.0, 1.0)
grid = sdfTools.Grid.Uniform(dims, offs, exts)

# create 2 shapes
sphere  = sdfTools.Sdf.Sphere(center=(1.0, 0.5, 0.5),
                              radius=0.4, inside=True)

segment = sdfTools.Sdf.Segment(start=(0.3, 0.5, 0.5),
                               end  =(1.7, 0.5, 0.5),
                               radius = 0.2, inside=True)

# create a union of the 2 shapes:
# first apply one shape
sphere.apply(grid)
# then apply the other on the same grid, with union operation
segment.interiorUnion(grid)

grid.dumpBov("union")
