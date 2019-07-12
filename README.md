# sdfTools

A simple tool with python interface to create signed distance function based geometries.

## Installation

Installing the tool requires:

- unix environment
- compiler supporting `c++11` or higher
- cmake 3.8 or higher
- python interpreter 3.6 or higher
- pip

```bash
git clone git@github.com:amlucas/sdfTools.git --recursive
cd sdfTools
make install
```

The installation can be tested by invoking

```bash
cd tests
make test
```

This operation requires [atest](https://gitlab.ethz.ch/mavt-cse/atest).


## Usage

```python
import sdfTools

offs = (0., 0., 0.)
dims = (64, 64, 64)
exts = (1.0, 1.0, 1.0)
center = (0.5, 0.5, 0.5)
radius = 0.4

# create a grid
grid = sdfTools.Grid.Uniform(dims, offs, exts)

# create SDF shape representation and apply it to the grid
sphere = sdfTools.Sdf.Sphere(center, radius, inside=True)
sphere.apply(grid)

# dump to a file in .bov format
grid.dumpBov("sphere")
```

