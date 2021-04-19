class Uniform:
    r"""
        container to hold SDF grid data

    
    """
    def __init__():
        r"""__init__(self: sdf_tools.Grid.Uniform, dimensions: sdf_tools.int3, offsets: sdf_tools.real3, extents: sdf_tools.real3) -> None


            Create an empty uniform grid of given size.

            Args:
                dimensions: number of cells along each dimension
                offsets: start of the domain
                extents: size of the domain
        

        """
        pass

    def dump_to_bov():
        r"""dump_to_bov(self: sdf_tools.Grid.Uniform, basename: str) -> None


          Dump the data in ``bov`` format

          Args:
              basename: base filename to dump to
        

        """
        pass

    def dump_to_sdf():
        r"""dump_to_sdf(self: sdf_tools.Grid.Uniform, basename: str) -> None


          Dump data in custom ``.sdf`` format

          Args:
              basename: base filename to dump to
        

        """
        pass

    def evaluate_sdf():
        r"""evaluate_sdf(self: sdf_tools.Grid.Uniform, arg0: sdf_tools.Sdf.Sdf) -> None

        """
        pass

    def evaluate_sdf_periodic():
        r"""evaluate_sdf_periodic(self: sdf_tools.Grid.Uniform, arg0: sdf_tools.Sdf.Sdf) -> None

        """
        pass

    def extrude():
        r"""extrude(self: sdf_tools.Grid.Uniform, zoffset: float, zextent: float, nz: int) -> None


          extrude a SDF from 'xy' plane to 3 dimensions

          Args:
              zoffset: offset in new direction
              zextent: extent in new direction
              nz: resolution in new direction
        

        """
        pass

    def flip():
        r"""flip(self: sdf_tools.Grid.Uniform, map: str) -> None


          flip axes of the grid according to map.

          Args:
              map: flip map

          examples:
              * map = 'xyz' does not flip anything
              * map = 'yxz' flip x and y axes
              * map = 'zxy' z -> x, y -> z, x -> y
        

        """
        pass

    def get():
        r"""get(*args, **kwargs)
Overloaded function.

1. get(self: sdf_tools.Grid.Uniform) -> List[float]


            returns a list of all values in a flatten array.
        

2. get(self: sdf_tools.Grid.Uniform) -> List[float]


            returns a list of all values in a flatten array (const).
        

        """
        pass


