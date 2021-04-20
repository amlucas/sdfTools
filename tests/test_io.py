import unittest
import sdf_tools
import sdf_tools.Sdf as sdf
import os


class TestIO(unittest.TestCase):

    def create_grid(self):
        grid = sdf_tools.Grid.Uniform(dimensions=(4, 5, 6),
                                      offsets=(0, 0, 0),
                                      extents=(1, 1, 1))
        grid.evaluate_sdf(sdf.Sphere(center=(0.5, 0.5, 0.5),
                                     radius=0.4, inside=True))
        return grid

    def test_dump_missing_extension(self):
        grid = self.create_grid()

        with self.assertRaises(RuntimeError):
            grid.dump("missing_extension")

    def test_dump_wrong_extension(self):
        grid = self.create_grid()

        with self.assertRaises(RuntimeError):
            grid.dump("wrong_extension.notsupported")

    def test_dump_sdf(self):
        grid = self.create_grid()
        name = "test.sdf"
        grid.dump(name)
        os.remove(name) # cleanup

    def test_dump_bov(self):
        grid = self.create_grid()
        name = "test.bov"
        grid.dump(name)
        os.remove(name) # cleanup
        os.remove("test.values")

    def test_dump_vtk(self):
        grid = self.create_grid()
        name = "test.vtk"
        grid.dump(name)
        os.remove(name) # cleanup
