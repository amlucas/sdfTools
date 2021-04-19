import numpy as np
import unittest

import sdf_tools.Sdf as sdf
import sdf_tools


class TestGrid(unittest.TestCase):

    def test_fill_sphere(self):
        center = (0.5, 0.5, 0.5)
        radius = 0.4
        sphere = sdf.Sphere(center, radius, inside=True)


        offs = (0., 0., 0.)
        dims = (8, 8, 8)
        exts = (1.0, 1.0, 1.0)

        grid = sdf_tools.Grid.Uniform(dims, offs, exts)

        grid.evaluate_sdf(sphere)
        gdata = grid.get()
        gdata = np.array(gdata).reshape(dims)
        self.assertEqual(gdata[0,0,0], sphere.at((0,0,0)))
