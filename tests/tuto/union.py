#! /usr/bin/env python

import sdf_tools

offs = (0., 0., 0.)
dims = (128, 64, 64)
exts = (2.0, 1.0, 1.0)
grid = sdf_tools.Grid.Uniform(dims, offs, exts)

# create 2 shapes
sphere  = sdf_tools.Sdf.Sphere(center=(1.0, 0.5, 0.5),
                               radius=0.4, inside=True)

capsule = sdf_tools.Sdf.Capsule(start=(0.3, 0.5, 0.5),
                                end  =(1.7, 0.5, 0.5),
                                radius = 0.2, inside=True)

# create a union of the 2 shapes
my_sdf = sdf_tools.Sdf.Union(sphere, capsule)

# evaluate on the grid and dump to file
grid.applySdf(my_sdf)
grid.dumpBov("union")
