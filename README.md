# sdfTools

[![Documentation Status](https://readthedocs.org/projects/sdftools/badge/?version=latest)](https://sdftools.readthedocs.io/en/latest/?badge=latest)

A simple tool with python interface to create signed distance function fields.

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
python -m pip install .
```

The installation can be tested by invoking

```bash
cd tests
./run.sh test_*.py
```
