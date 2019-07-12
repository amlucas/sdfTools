#include "write_sdf.h"

#include <cstdio>
#include <sstream>
#include <type_traits>
#include <vector>

static const std::string ext = ".sdf";

void writeSdf(std::string basename, const Grid *grid)
{
    std::string fname = basename + ext;
    
    FILE *f = fopen(fname.c_str(), "wb");

    std::stringstream ss;

    auto h = grid->getSpacing();
    auto n = grid->getDimensions();
    auto ntot = n.x * n.y * n.z;
        
    ss << h.x << ' ' << h.y << ' ' << h.z << '\n';
    ss << n.x << ' ' << n.y << ' ' << n.z << '\n';

    std::string headerData = ss.str();

    fwrite(headerData.c_str(), sizeof(char), headerData.size(), f);
    fseek(f, sizeof(char) * headerData.size(), SEEK_CUR);
    fwrite(grid->data(), sizeof(real), ntot, f);
    
    fclose(f);
}
