#! /usr/bin/env python

import numpy as np
import sdf_tools

n = 5

offs = (0., 0., 0.)
dims = (n, n, n)
exts = (1.0, 1.0, 1.0)
start = (0.2, 0.5, 0.5)
end   = (0.8, 0.5, 0.5)
radius = 0.1

grid = sdf_tools.Grid.Uniform(dims, offs, exts)

segment = sdf_tools.Sdf.Segment(start, end, radius, inside=True)

segment.apply(grid)

np.savetxt("grid.txt", grid.get())

# TEST: analytical.segment
# cd analytical
# rm -rf *.txt
# ./segment.py
# mv grid.txt grid.out.txt
