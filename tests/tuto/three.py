#! /usr/bin/env python

import sdfTools

offs = (0., 0., 0.)
dims = (128, 64, 64)
exts = (2.0, 1.0, 1.0)
grid = sdfTools.Grid.Uniform(dims, offs, exts)

sphere = sdfTools.Sdf.Sphere(center=(1.0, 0.5, 0.5),
                             radius=0.4, inside=True)

segment0 = sdfTools.Sdf.Segment(start=(0.3, 0.5, 0.5),
                                end  =(1.7, 0.5, 0.5),
                                radius = 0.2, inside=True)

segment1 = sdfTools.Sdf.Segment(start=(1.3, 0.5, 0.1),
                                end  =(0.7, 0.5, 0.9),
                                radius = 0.2, inside=True)

sphere.apply(grid)
segment0.interiorUnion(grid)
segment1.interiorSubtractToGrid(grid)

grid.dumpBov("three")
