#! /usr/bin/env python

import sdf_tools

# first we need to allocate a uniform grid

offs = (0., 0., 0.) # start of the grid
dims = (64, 64, 64) # resolution of the grid
exts = (1.0, 1.0, 1.0) # extents of the grid

grid = sdf_tools.Grid.Uniform(dims, offs, exts)

# now we create a sphere description
center = (0.5, 0.5, 0.5)
radius = 0.4

sphere = sdf_tools.Sdf.Sphere(center, radius, inside=True)

# apply the sdf to the grid points
grid.evaluate_sdf(sphere)

# dump the grid to .bov format, can be open with visit
grid.dump_to_bov("sphere")
