#! /usr/bin/env python

import sdf_tools

offs = (0., 0., 0.)
dims = (128, 64, 64)
exts = (2.0, 1.0, 1.0)
grid = sdf_tools.Grid.Uniform(dims, offs, exts)

sphere = sdf_tools.Sdf.Sphere(center=(1.0, 0.5, 0.5),
                              radius=0.4, inside=True)

capsule0 = sdf_tools.Sdf.Capsule(start=(0.3, 0.5, 0.5),
                                 end  =(1.7, 0.5, 0.5),
                                 radius = 0.2, inside=True)

capsule1 = sdf_tools.Sdf.Capsule(start=(1.3, 0.5, 0.1),
                                 end  =(0.7, 0.5, 0.9),
                                 radius = 0.2, inside=True)

my_sdf = sdf_tools.Sdf.Difference(sdf_tools.Sdf.Union(sphere, capsule0),
                                  capsule1)

grid.applySdf(my_sdf)
grid.dumpBov("three")
