import unittest
import sdf_tools.Sdf as sdf


class TestBasicSDFs(unittest.TestCase):

    def test_box(self):
        box = sdf.Box(low=[-1,-2,-1],
                      high=[1,2,1],
                      inside=True)

        self.assertEqual(box.at([0, 0, 0]), -1)
        self.assertEqual(box.at([0, 3, 0]),  1)
        self.assertEqual(box.at([1, 0, 1]),  0)

    def test_edges_2d(self):
        box = sdf.Edges(edges = [[-1, -2], [1, -2], [1, 2], [-1, 2]],
                        inside=True)

        self.assertEqual(box.at([0, 0, 0]), -1)
        self.assertEqual(box.at([0, 3, 0]),  1)
        self.assertEqual(box.at([1, 2, 0]),  0)
        self.assertEqual(box.at([1, 0, 0]),  0)

    def test_plate(self):
        plate = sdf.Plate(point=[1, 2, 3],
                          normal=[0, 1, 0])

        self.assertEqual(plate.at([0, 0, 0]), -2)
        self.assertEqual(plate.at([7, 0, 0]), -2)
        self.assertEqual(plate.at([0, 1, 0]), -1)
        self.assertEqual(plate.at([0, 3, 0]),  1)

    def test_capsule(self):
        cap = sdf.Capsule(start=[0, -1, 0],
                          end=[0, 1, 0],
                          radius=0.5,
                          inside=True)

        self.assertEqual(cap.at([0, 0, 0]), -0.5)
        self.assertEqual(cap.at([0, 1, 0]), -0.5)
        self.assertEqual(cap.at([0, -1, 0]), -0.5)
        self.assertEqual(cap.at([1, -1, 0]), 0.5)
        self.assertEqual(cap.at([0, -1.5, 0]), 0)

    def test_sphere(self):
        sph = sdf.Sphere(center=[0, -1, 0],
                         radius=2,
                         inside=True)

        self.assertEqual(sph.at([0, 0, 0]), -1)
        self.assertEqual(sph.at([0, -1, 0]), -2)
        self.assertEqual(sph.at([0, -1, 2]), 0)
        self.assertEqual(sph.at([0, -3, 0]), 0)
        self.assertEqual(sph.at([0, 3, 0]), 2)

    def test_mesh(self):
        import trimesh
        mesh = trimesh.creation.icosphere(radius=1, subdivisions=3)

        sph = sdf.FromMesh(faces=mesh.faces.tolist(),
                           vertices=mesh.vertices.tolist(),
                           inside=True)

        self.assertAlmostEqual(sph.at([0, 0, 0]), -1, places=2)
        self.assertAlmostEqual(sph.at([1, 0, 0]), 0, places=2)
        self.assertAlmostEqual(sph.at([2, 0, 0]), 1, places=2)
        self.assertAlmostEqual(sph.at([2, 2, 0]), 8**0.5-1, places=2)
