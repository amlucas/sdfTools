namespace common
{    
    template <typename SDF, typename Op>
    static void applyOperation(const SDF *sdf, Grid *grid, Op op)
    {
        auto dims = grid->getDimensions();
        auto exts = grid->getExtents();
        auto offs = grid->getOffsets();
        real *data = grid->data();

        real3 d = exts / dims;

        for (int iz = 0; iz < dims.z; ++iz)
            for (int iy = 0; iy < dims.y; ++iy)
                for (int ix = 0; ix < dims.x; ++ix) {
                    real3 r;
                    r.x = offs.x + ix * d.x;
                    r.y = offs.y + iy * d.y;
                    r.z = offs.z + iz * d.z;

                    const int i = ix + dims.x * (iy + dims.y * iz);
                    
                    data[i] = op(sdf->at(r), data[i]);
                }    
    }

    template <typename SDF>
    void apply(const SDF *sdf, Grid *grid)
    {
        applyOperation(sdf, grid, [](real s, real g){return s;});
    }

    template <typename SDF>
    void applyComplement(const SDF *sdf, Grid *grid)
    {
        applyOperation(sdf, grid, [](real s, real g){return -s;});
    }

    template <typename SDF>
    void interiorUnion(const SDF *sdf, Grid *grid)
    {
        applyOperation(sdf, grid, [](real s, real g){return std::max(s, g);});
    }

    template <typename SDF>
    void interiorIntersection(const SDF *sdf, Grid *grid)
    {
        applyOperation(sdf, grid, [](real s, real g){return std::min(s, g);});
    }

    template <typename SDF>
    void interiorSubtractToGrid(const SDF *sdf, Grid *grid)
    {
        applyOperation(sdf, grid, [](real s, real g){return std::max(-s, g);});
    }

    template <typename SDF>
    void interiorSubtractGrid(const SDF *sdf, Grid *grid)
    {
        applyOperation(sdf, grid, [](real s, real g){return std::max(s, -g);});
    }
}
