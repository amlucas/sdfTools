#! /usr/bin/env python

import numpy as np
import sdf_tools
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--map',  type=str, required=True)
args = parser.parse_args()

n0 = 8

offs = (0., 0., 0.)
dims = (n0, 3*n0, 2*n0)
exts = (1.0, 3.0, 2.0)

center = (0.35, 0.75, 0.5)
radius = 0.2

grid = sdf_tools.Grid.Uniform(dims, offs, exts)

sphere = sdf_tools.Sdf.Sphere(center, radius, inside=True)

sphere.apply(grid)

grid.flip(args.map)

np.savetxt("grid.txt", grid.get())

# TEST: grid_operations.flip.xyz
# cd grid_operations
# rm -rf *.txt
# ./flip.py --map 'xyz'
# mv grid.txt grid.out.txt

# TEST: grid_operations.flip.yxz
# cd grid_operations
# rm -rf *.txt
# ./flip.py --map 'yxz'
# mv grid.txt grid.out.txt

# TEST: grid_operations.flip.zxy
# cd grid_operations
# rm -rf *.txt
# ./flip.py --map 'zxy'
# mv grid.txt grid.out.txt
