class Sdf:
    r"""
        Base sdf class.
    
    """
    def apply():
        r"""apply(grid: Grid) -> None


        Compute the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def applyComplement():
        r"""applyComplement(grid: Grid) -> None


        Compute the complement of the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyComplementPeriodic():
        r"""applyComplementPeriodic(grid: Grid) -> None


        Compute the complement of the given sdf shape and its periodic images for each point
        of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyPeriodic():
        r"""applyPeriodic(grid: Grid) -> None


        Compute the given sdf shape and its periodic images for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def interiorIntersection():
        r"""interiorIntersection(grid: Grid) -> None


        Compute the interior intersection of the given sdf with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorIntersectionPeriodic():
        r"""interiorIntersectionPeriodic(grid: Grid) -> None


        Compute the interior intersection of the given sdf and its periodic images 
        with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorSubtractGrid():
        r"""interiorSubtractGrid(grid: Grid) -> None


        Compute the interior subtraction of the given sdf by the given grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractGridPeriodic():
        r"""interiorSubtractGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given sdf and its periodic images by the given
        grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractToGrid():
        r"""interiorSubtractToGrid(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorSubtractToGridPeriodic():
        r"""interiorSubtractToGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf and its 
        periodic images.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorUnion():
        r"""interiorUnion(grid: Grid) -> None


        Compute the interior union of the given sdf with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass

    def interiorUnionPeriodic():
        r"""interiorUnionPeriodic(grid: Grid) -> None


        Compute the interior union of the given sdf and its periodic images with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass

class Box(Sdf):
    r"""
        Box aligned with axes
    
    """
    def __init__():
        r"""__init__(lower_bound: Tuple[float, float, float], upper_bound: Tuple[float, float, float], inside: bool) -> None



            Args:
                lower_bound: lower corner of the box
                upper_bound: upper corner of the box
                inside: ``True`` if the interior is inside the given shape
        

        """
        pass

    def apply():
        r"""apply(grid: Grid) -> None


        Compute the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def applyComplement():
        r"""applyComplement(grid: Grid) -> None


        Compute the complement of the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyComplementPeriodic():
        r"""applyComplementPeriodic(grid: Grid) -> None


        Compute the complement of the given sdf shape and its periodic images for each point
        of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyPeriodic():
        r"""applyPeriodic(grid: Grid) -> None


        Compute the given sdf shape and its periodic images for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def interiorIntersection():
        r"""interiorIntersection(grid: Grid) -> None


        Compute the interior intersection of the given sdf with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorIntersectionPeriodic():
        r"""interiorIntersectionPeriodic(grid: Grid) -> None


        Compute the interior intersection of the given sdf and its periodic images 
        with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorSubtractGrid():
        r"""interiorSubtractGrid(grid: Grid) -> None


        Compute the interior subtraction of the given sdf by the given grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractGridPeriodic():
        r"""interiorSubtractGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given sdf and its periodic images by the given
        grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractToGrid():
        r"""interiorSubtractToGrid(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorSubtractToGridPeriodic():
        r"""interiorSubtractToGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf and its 
        periodic images.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorUnion():
        r"""interiorUnion(grid: Grid) -> None


        Compute the interior union of the given sdf with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass

    def interiorUnionPeriodic():
        r"""interiorUnionPeriodic(grid: Grid) -> None


        Compute the interior union of the given sdf and its periodic images with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass

class Edges(Sdf):
    r"""
        closed polygon defined from edges
    
    """
    def __init__():
        r"""__init__(edges: List[List[float[2]]], inside: bool) -> None



            Args:
                edges: list of vertices positions (2D)
                inside: ``True`` if the interior is inside the given shape
        

        """
        pass

    def apply():
        r"""apply(grid: Grid) -> None


        Compute the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def applyComplement():
        r"""applyComplement(grid: Grid) -> None


        Compute the complement of the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyComplementPeriodic():
        r"""applyComplementPeriodic(grid: Grid) -> None


        Compute the complement of the given sdf shape and its periodic images for each point
        of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyPeriodic():
        r"""applyPeriodic(grid: Grid) -> None


        Compute the given sdf shape and its periodic images for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def interiorIntersection():
        r"""interiorIntersection(grid: Grid) -> None


        Compute the interior intersection of the given sdf with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorIntersectionPeriodic():
        r"""interiorIntersectionPeriodic(grid: Grid) -> None


        Compute the interior intersection of the given sdf and its periodic images 
        with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorSubtractGrid():
        r"""interiorSubtractGrid(grid: Grid) -> None


        Compute the interior subtraction of the given sdf by the given grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractGridPeriodic():
        r"""interiorSubtractGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given sdf and its periodic images by the given
        grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractToGrid():
        r"""interiorSubtractToGrid(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorSubtractToGridPeriodic():
        r"""interiorSubtractToGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf and its 
        periodic images.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorUnion():
        r"""interiorUnion(grid: Grid) -> None


        Compute the interior union of the given sdf with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass

    def interiorUnionPeriodic():
        r"""interiorUnionPeriodic(grid: Grid) -> None


        Compute the interior union of the given sdf and its periodic images with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass

class Plate(Sdf):
    r"""
        plate defined by one point and the normal vector

    
    """
    def __init__():
        r"""__init__(point: Tuple[float, float, float], normal: Tuple[float, float, float]) -> None


            Args:
                point: one point on the plane
                normal: the normal vector (not necessarily normalized, but must be non-zero) 
                        pointing inside
        

        """
        pass

    def apply():
        r"""apply(grid: Grid) -> None


        Compute the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def applyComplement():
        r"""applyComplement(grid: Grid) -> None


        Compute the complement of the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyComplementPeriodic():
        r"""applyComplementPeriodic(grid: Grid) -> None


        Compute the complement of the given sdf shape and its periodic images for each point
        of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyPeriodic():
        r"""applyPeriodic(grid: Grid) -> None


        Compute the given sdf shape and its periodic images for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def interiorIntersection():
        r"""interiorIntersection(grid: Grid) -> None


        Compute the interior intersection of the given sdf with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorIntersectionPeriodic():
        r"""interiorIntersectionPeriodic(grid: Grid) -> None


        Compute the interior intersection of the given sdf and its periodic images 
        with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorSubtractGrid():
        r"""interiorSubtractGrid(grid: Grid) -> None


        Compute the interior subtraction of the given sdf by the given grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractGridPeriodic():
        r"""interiorSubtractGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given sdf and its periodic images by the given
        grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractToGrid():
        r"""interiorSubtractToGrid(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorSubtractToGridPeriodic():
        r"""interiorSubtractToGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf and its 
        periodic images.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorUnion():
        r"""interiorUnion(grid: Grid) -> None


        Compute the interior union of the given sdf with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass

    def interiorUnionPeriodic():
        r"""interiorUnionPeriodic(grid: Grid) -> None


        Compute the interior union of the given sdf and its periodic images with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass

class Segment(Sdf):
    r"""
        segment defined by end points and radius

    
    """
    def __init__():
        r"""__init__(start: Tuple[float, float, float], end: Tuple[float, float, float], radius: float, inside: bool) -> None



            Args:
                start: first end of the segment
                end:  second end of the segment
                radius: radius of the segment
                inside: whether the domain is inside the sphere or outside of it
        

        """
        pass

    def apply():
        r"""apply(grid: Grid) -> None


        Compute the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def applyComplement():
        r"""applyComplement(grid: Grid) -> None


        Compute the complement of the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyComplementPeriodic():
        r"""applyComplementPeriodic(grid: Grid) -> None


        Compute the complement of the given sdf shape and its periodic images for each point
        of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyPeriodic():
        r"""applyPeriodic(grid: Grid) -> None


        Compute the given sdf shape and its periodic images for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def interiorIntersection():
        r"""interiorIntersection(grid: Grid) -> None


        Compute the interior intersection of the given sdf with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorIntersectionPeriodic():
        r"""interiorIntersectionPeriodic(grid: Grid) -> None


        Compute the interior intersection of the given sdf and its periodic images 
        with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorSubtractGrid():
        r"""interiorSubtractGrid(grid: Grid) -> None


        Compute the interior subtraction of the given sdf by the given grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractGridPeriodic():
        r"""interiorSubtractGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given sdf and its periodic images by the given
        grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractToGrid():
        r"""interiorSubtractToGrid(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorSubtractToGridPeriodic():
        r"""interiorSubtractToGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf and its 
        periodic images.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorUnion():
        r"""interiorUnion(grid: Grid) -> None


        Compute the interior union of the given sdf with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass

    def interiorUnionPeriodic():
        r"""interiorUnionPeriodic(grid: Grid) -> None


        Compute the interior union of the given sdf and its periodic images with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass

class Sphere(Sdf):
    r"""
        sphere defined by center and radius

    
    """
    def __init__():
        r"""__init__(center: Tuple[float, float, float], radius: float, inside: bool) -> None



            Args:
                center: center of the sphere
                radius: radius of the sphere
                inside: whether the domain is inside the sphere or outside of it
        

        """
        pass

    def apply():
        r"""apply(grid: Grid) -> None


        Compute the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def applyComplement():
        r"""applyComplement(grid: Grid) -> None


        Compute the complement of the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyComplementPeriodic():
        r"""applyComplementPeriodic(grid: Grid) -> None


        Compute the complement of the given sdf shape and its periodic images for each point
        of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    

        """
        pass

    def applyPeriodic():
        r"""applyPeriodic(grid: Grid) -> None


        Compute the given sdf shape and its periodic images for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    

        """
        pass

    def interiorIntersection():
        r"""interiorIntersection(grid: Grid) -> None


        Compute the interior intersection of the given sdf with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorIntersectionPeriodic():
        r"""interiorIntersectionPeriodic(grid: Grid) -> None


        Compute the interior intersection of the given sdf and its periodic images 
        with the given grid.

        Args:
            grid: the grid to apply the intersection to
    

        """
        pass

    def interiorSubtractGrid():
        r"""interiorSubtractGrid(grid: Grid) -> None


        Compute the interior subtraction of the given sdf by the given grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractGridPeriodic():
        r"""interiorSubtractGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given sdf and its periodic images by the given
        grid.

        Args:
            grid: the grid to subtract
    

        """
        pass

    def interiorSubtractToGrid():
        r"""interiorSubtractToGrid(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorSubtractToGridPeriodic():
        r"""interiorSubtractToGridPeriodic(grid: Grid) -> None


        Compute the interior subtraction of the given grid by the given sdf and its 
        periodic images.

        Args:
            grid: the grid to apply the subtraction to
    

        """
        pass

    def interiorUnion():
        r"""interiorUnion(grid: Grid) -> None


        Compute the interior union of the given sdf with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass

    def interiorUnionPeriodic():
        r"""interiorUnionPeriodic(grid: Grid) -> None


        Compute the interior union of the given sdf and its periodic images with the given grid.

        Args:
            grid: the grid to apply the union to
    

        """
        pass


