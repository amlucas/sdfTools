#! /usr/bin/env python

import numpy as np
import sdfTools

n = 32

offs = (0., 0., 0.)
dims = (n, n, n)
exts = (1.0, 1.0, 1.0)
center = (0.5, 0.5, 0.5)
radius = 0.4

grid = sdfTools.Grid.Uniform(dims, offs, exts)

sphere = sdfTools.Sdf.Sphere(center, radius, inside=True)

sphere.apply(grid)

sdfTools.Grid.write_bov("sphere", grid)
