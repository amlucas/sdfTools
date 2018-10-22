namespace common
{
    
    template <typename SDF>
    void apply(const SDF *sdf, Grid *grid)
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

                    data[ix + dims.x * (iy + dims.y * iz)] = sdf->at(r);
                }    
    }

}
