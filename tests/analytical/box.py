#! /usr/bin/env python

import numpy as np
import sdfTools

n = 5

offs = (0., 0., 0.)
dims = (n, n, n)
exts = (1.0, 1.0, 1.0)

grid = sdfTools.Grid.Uniform(dims, offs, exts)

box = sdfTools.Sdf.Box((0.2, 0.2, 0.2),
                       (0.8, 0.8, 0.8),
                       inside=True)

box.apply(grid)

np.savetxt("grid.txt", grid.get())

# TEST: analytical.box
# cd analytical
# rm -rf *.txt
# ./box.py
# mv grid.txt grid.out.txt
