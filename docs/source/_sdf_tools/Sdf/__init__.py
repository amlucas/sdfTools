class Sdf:
    r"""
        Base sdf class.
    
    """
    def at():
        r"""at(self: sdf_tools.Sdf.Sdf, r: sdf_tools.real3) -> float


        Evaluate the SDF field at the given position.

        Args:
            r: The position where to evaluate the SDF.
    

        """
        pass

class Box(Sdf):
    r"""
        Box aligned with axes
    
    """
    def __init__():
        r"""__init__(self: sdf_tools.Sdf.Box, low: sdf_tools.real3, high: sdf_tools.real3, inside: bool) -> None



            Args:
                low: Lower corner of the box.
                high: Upper corner of the box.
                inside: ``True`` if the interior is inside the given shape.
        

        """
        pass

    def at():
        r"""at(self: sdf_tools.Sdf.Sdf, r: sdf_tools.real3) -> float


        Evaluate the SDF field at the given position.

        Args:
            r: The position where to evaluate the SDF.
    

        """
        pass

class Capsule(Sdf):
    r"""
        Capsule defined by a segment and a radius.

    
    """
    def __init__():
        r"""__init__(self: sdf_tools.Sdf.Capsule, start: sdf_tools.real3, end: sdf_tools.real3, radius: float, inside: bool) -> None



            Args:
                start: First end of the segment.
                end:  Second end of the segment.
                radius: Radius of the capsule.
                inside: Whether the domain is inside the capsule or outside of it.
        

        """
        pass

    def at():
        r"""at(self: sdf_tools.Sdf.Sdf, r: sdf_tools.real3) -> float


        Evaluate the SDF field at the given position.

        Args:
            r: The position where to evaluate the SDF.
    

        """
        pass

class Complement(Sdf):
    r"""Reverse interior and exterior.
    """
    def __init__():
        r"""__init__(self: sdf_tools.Sdf.Complement, sdf: sdf_tools.Sdf.Sdf) -> None



        Args:
            sdf: The original sdf.

        

        """
        pass

    def at():
        r"""at(self: sdf_tools.Sdf.Sdf, r: sdf_tools.real3) -> float


        Evaluate the SDF field at the given position.

        Args:
            r: The position where to evaluate the SDF.
    

        """
        pass

class Difference(Sdf):
    r"""Difference between two SDF objects.
    """
    def __init__():
        r"""__init__(self: sdf_tools.Sdf.Difference, a: sdf_tools.Sdf.Sdf, b: sdf_tools.Sdf.Sdf) -> None



        Args:
            a: The original sdf.
            b: The sdf of the object that should be removed from the original.

        

        """
        pass

    def at():
        r"""at(self: sdf_tools.Sdf.Sdf, r: sdf_tools.real3) -> float


        Evaluate the SDF field at the given position.

        Args:
            r: The position where to evaluate the SDF.
    

        """
        pass

class Edges(Sdf):
    r"""
        Closed polygon defined from edges in the xy plane.
    
    """
    def __init__():
        r"""__init__(self: sdf_tools.Sdf.Edges, edges: List[sdf_tools.real2], inside: bool, nsamples: int = 20) -> None



            Args:
                edges: List of vertices positions (2D).
                inside: ``True`` if the interior is inside the given shape.
                nsamples: Number of samples to find the sign of the SDF (more is more accurate).
        

        """
        pass

    def at():
        r"""at(self: sdf_tools.Sdf.Sdf, r: sdf_tools.real3) -> float


        Evaluate the SDF field at the given position.

        Args:
            r: The position where to evaluate the SDF.
    

        """
        pass

class Intersection(Sdf):
    r"""Intersection between two SDF objects.
    """
    def __init__():
        r"""__init__(self: sdf_tools.Sdf.Intersection, a: sdf_tools.Sdf.Sdf, b: sdf_tools.Sdf.Sdf) -> None



        Args:
            a: The first sdf.
            b: The second sdf.

        

        """
        pass

    def at():
        r"""at(self: sdf_tools.Sdf.Sdf, r: sdf_tools.real3) -> float


        Evaluate the SDF field at the given position.

        Args:
            r: The position where to evaluate the SDF.
    

        """
        pass

class PiecewisePipe(Sdf):
    r"""
        The union of many connected capsules, forming a piecewise linear pipe with a constant radius.

    
    """
    def __init__():
        r"""__init__(self: sdf_tools.Sdf.PiecewisePipe, vertices: List[sdf_tools.real3], radius: float, inside: bool) -> None



            Args:
                vertices: Coordinates of the points forming the center line.
                radius: Radius of the capsule.
                inside: Whether the domain is inside the capsule or outside of it.
        

        """
        pass

    def at():
        r"""at(self: sdf_tools.Sdf.Sdf, r: sdf_tools.real3) -> float


        Evaluate the SDF field at the given position.

        Args:
            r: The position where to evaluate the SDF.
    

        """
        pass

class Plate(Sdf):
    r"""
        Plate defined by one point on the surface and the normal vector, pointing inside.

    
    """
    def __init__():
        r"""__init__(self: sdf_tools.Sdf.Plate, point: sdf_tools.real3, normal: sdf_tools.real3) -> None


            Args:
                point: One point on the plane.
                normal: The normal vector (not necessarily normalized, but must be non-zero)
                        pointing inside.
        

        """
        pass

    def at():
        r"""at(self: sdf_tools.Sdf.Sdf, r: sdf_tools.real3) -> float


        Evaluate the SDF field at the given position.

        Args:
            r: The position where to evaluate the SDF.
    

        """
        pass

class Sphere(Sdf):
    r"""
        Sphere defined by its center and radius.

    
    """
    def __init__():
        r"""__init__(self: sdf_tools.Sdf.Sphere, center: sdf_tools.real3, radius: float, inside: bool) -> None



            Args:
                center: Center of the sphere.
                radius: Radius of the sphere.
                inside: Whether the domain is inside the sphere or outside of it.
        

        """
        pass

    def at():
        r"""at(self: sdf_tools.Sdf.Sdf, r: sdf_tools.real3) -> float


        Evaluate the SDF field at the given position.

        Args:
            r: The position where to evaluate the SDF.
    

        """
        pass

class Union(Sdf):
    r"""Union between two SDF objects.
    """
    def __init__():
        r"""__init__(self: sdf_tools.Sdf.Union, a: sdf_tools.Sdf.Sdf, b: sdf_tools.Sdf.Sdf) -> None



        Args:
            a: The first sdf.
            b: The second sdf.

        

        """
        pass

    def at():
        r"""at(self: sdf_tools.Sdf.Sdf, r: sdf_tools.real3) -> float


        Evaluate the SDF field at the given position.

        Args:
            r: The position where to evaluate the SDF.
    

        """
        pass


