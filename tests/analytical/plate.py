#! /usr/bin/env python

import numpy as np
import sdfTools

offs = [0., 0., 0.]
dims = [32, 32, 64]
exts = [1.0, 2.0, 4.0]

grid = sdfTools.Grid.Uniform(dims, offs, exts)

plate = sdfTools.Sdf.Plate(point  = [0.1*exts[0], 0, 0],
                           normal = [1, 0, 0])

plate.apply(grid)

sdfTools.Grid.write_bov("plate", grid)
