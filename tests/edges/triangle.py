#! /usr/bin/env python

import numpy as np
import sdfTools

n = 8

offs = (0., 0., 0.)
dims = (n, n, 1)
exts = (2.0, 2.0, 0.0)

grid = sdfTools.Grid.Uniform(dims, offs, exts)

#create a triangle
edges = [[0.1, 0.1],
         [0.9, 0.1],
         [0.5, 0.9]]

triangle = sdfTools.Sdf.Edges(edges, inside=False)

triangle.apply(grid)

np.savetxt("grid.txt", grid.get())

# TEST: edges.triangle
# cd edges
# rm -rf *.txt
# ./triangle.py
# mv grid.txt grid.out.txt

