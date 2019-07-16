#! /usr/bin/env python

import sdfTools

# first we need to allocate a uniform grid

offs = (0., 0., 0.) # start of the grid
dims = (64, 64, 64) # resolution of the grid
exts = (1.0, 1.0, 1.0) # extents of the grid

grid = sdfTools.Grid.Uniform(dims, offs, exts)

# now we create a sphere description
center = (0.5, 0.5, 0.5)
radius = 0.4

sphere = sdfTools.Sdf.Sphere(center, radius, inside=True)

# apply the description to the grid
sphere.apply(grid)

# dump the grid to .bov format, can be open with visit
grid.dumpBov("sphere")
