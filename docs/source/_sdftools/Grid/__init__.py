class Uniform:
    r"""
        container to hold SDF grid data

    
    """
    def __init__():
        r"""__init__(dimensions: Tuple[int, int, int], offsets: Tuple[float, float, float], extents: Tuple[float, float, float]) -> None


            Create an empty uniform grid of given size.

            Args:
                dimensions: number of cells along each dimension
                offsets: start of the domain
                extents: size of the domain
        

        """
        pass

    def applySdfComplement():
        r"""applySdfComplement(self: Grid.Uniform) -> None


          apply complement unary operation 
        

        """
        pass

    def applySdfInteriorIntersection():
        r"""applySdfInteriorIntersection(other: Grid.Uniform) -> None


          apply interior intersection between this grid and another given grid 

          Args:
              other: the other grid 
        

        """
        pass

    def applySdfInteriorUnion():
        r"""applySdfInteriorUnion(other: Grid.Uniform) -> None


          apply interior union between this grid and another given grid 

          Args:
              other: the other grid 
        

        """
        pass

    def applySdfSubtract():
        r"""applySdfSubtract(other: Grid.Uniform) -> None


          apply interior subtract between this grid and another given grid 
          Args:
              other: the other grid 
        

        """
        pass

    def dumpBov():
        r"""dumpBov(basename: str) -> None


          Dump the data in ``bov`` format

          Args:
              basename: base filename to dump to
        

        """
        pass

    def dumpSdf():
        r"""dumpSdf(basename: str) -> None


          Dump data in custom ``.sdf`` format

          Args:
              basename: base filename to dump to
        

        """
        pass

    def extrude():
        r"""extrude(zoffset: float, zextent: float, nz: int) -> None


          extrude a SDF from 'xy' plane to 3 dimensions

          Args:
              zoffset: offset in new direction
              zextent: extent in new direction
              nz: resolution in new direction
        

        """
        pass

    def flip():
        r"""flip(map: str) -> None


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

1. get(self: Grid.Uniform) -> List[float]


            returns a list of all values in a flatten array.
        

2. get(self: Grid.Uniform) -> List[float]


            returns a list of all values in a flatten array (const).
        

        """
        pass


