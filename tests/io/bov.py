#! /usr/bin/env python

import numpy as np
import sdfTools, struct

offs = (0., 0., 0.)
dims = (3, 4, 5)
exts = (1.0, 1.0, 1.0)
center = (0.5, 0.5, 0.5)
radius = 0.4

grid = sdfTools.Grid.Uniform(dims, offs, exts)

sphere = sdfTools.Sdf.Sphere(center, radius, inside=True)

sphere.apply(grid)

basename="sphere"

grid.dumpBov(basename)

rawdata = open(basename+".values", "rb").read()

nfloats = dims[0]*dims[1]*dims[2]
data = np.array(struct.unpack("@" + "f" * nfloats, rawdata))

np.savetxt("bov_values.txt", data)


# TEST: io.bov.header
# cd io
# rm -rf *.txt sphere.bov sphere.values
# ./bov.py
# cat   sphere.bov     > bov.out.txt

# TEST: io.bov.values
# cd io
# rm -rf *.txt sphere.bov sphere.values
# ./bov.py
# cat bov_values.txt > bov.out.txt

