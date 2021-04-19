import unittest
import sdf_tools.Sdf as sdf


class TestBasicSDFs(unittest.TestCase):

    def test_union_plates(self):
        plates = sdf.Union(sdf.Plate(point=[0,-1,0], normal=[0,-1,0]),
                           sdf.Plate(point=[0, 1,0], normal=[0, 1,0]))

        self.assertEqual(plates.at([0, 0, 0]), -1)

    def test_union_boxes(self):
        box = sdf.Union(sdf.Box(low=[-1,-2,-1], high=[1,0,1], inside=True),
                        sdf.Box(low=[-1, 0,-1], high=[1,2,1], inside=True))

        self.assertEqual(box.at([0, 3, 0]),  1)
        self.assertEqual(box.at([1, 0, 1]),  0)
