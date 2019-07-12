#! /usr/bin/env python

import numpy as np
import sdfTools

offs = [0., 0., 0.]
dims = [3, 4, 5]
exts = [1.0, 2.0, 4.0]

grid = sdfTools.Grid.Uniform(dims, offs, exts)

sdfTools.Sdf.Plate(point  = [0.1*exts[0], 0, 0],
                   normal = [ 1, 0, 0]).apply(grid)

sdfTools.Sdf.Plate(point  = [0.9*exts[0], 0, 0],
                   normal = [-1, 0, 0]).interiorIntersection(grid)


np.savetxt("grid.txt", grid.get())

# TEST: analytical.plates
# cd analytical
# rm -rf *.txt
# ./plates.py
# mv grid.txt grid.out.txt

