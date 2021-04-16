#! /usr/bin/env python

import numpy as np
import sdf_tools, struct

offs = (0., 0., 0.)
dims = (3, 4, 5)
exts = (1.0, 1.0, 1.0)
center = (0.5, 0.5, 0.5)
radius = 0.4

grid = sdf_tools.Grid.Uniform(dims, offs, exts)

sphere = sdf_tools.Sdf.Sphere(center, radius, inside=True)

sphere.apply(grid)


basename="sphere"
grid.dumpSdf(basename)
rawdata = open(basename+".sdf", "rb").read()

nfloats = dims[0]*dims[1]*dims[2]
start = len(rawdata) - nfloats * 4
data = np.array(struct.unpack("@" + "f" * nfloats, rawdata[start:]))

np.savetxt("sdf_values.txt", data)

# TEST: io.sdf.header
# cd io
# rm -rf *.txt sphere.sdf
# ./sdf.py
# head -n 2 sphere.sdf > sdf.out.txt

# TEST: io.sdf.values
# cd io
# rm -rf *.txt sphere.sdf
# ./sdf.py
# cat sdf_values.txt > sdf.out.txt
