#! /usr/bin/env python

import numpy as np
import sdfTools

offs = (0., 0., 0.)
dims = (3, 4, 5)
exts = (1.0, 1.0, 1.0)
center = (0.5, 0.5, 0.5)
radius = 0.4

grid = sdfTools.Grid.Uniform(dims, offs, exts)

sphere = sdfTools.Sdf.Sphere(center, radius, inside=True)

sphere.apply(grid)

grid.dumpBov("sphere")

# TEST: io.bov.header
# cd io
# rm -rf *.txt sphere.bov sphere.values
# ./bov.py
# cat   sphere.bov     > bov.out.txt

# TEST: io.bov.values
# cd io
# rm -rf *.txt sphere.bov sphere.values
# ./bov.py
# od -f sphere.values > bov.out.txt

