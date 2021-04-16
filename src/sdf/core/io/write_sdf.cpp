#include "write_sdf.h"

#include <core/utils/file.h>

#include <sstream>
#include <type_traits>
#include <vector>

static const std::string ext = ".sdf";

static std::vector<float> getFloatData(const Grid *grid)
{
    const auto& data = grid->getData();
    std::vector<float> d;
    d.reserve(data.size());

    for (auto val : data) d.push_back(val);

    return d;
}

void writeSdf(std::string basename, const Grid *grid)
{
    const std::string fname = basename + ext;
    
    FILE *f = safeOpen(fname.c_str(), "wb");

    std::stringstream ss;

    const auto l = grid->getExtents();
    const auto n = grid->getDimensions();
    const auto data = getFloatData(grid);
        
    ss << l.x << ' ' << l.y << ' ' << l.z << '\n';
    ss << n.x << ' ' << n.y << ' ' << n.z << '\n';

    const std::string headerData = ss.str();

    fwrite(headerData.c_str(), sizeof(char), headerData.size(), f);
    fseek(f, sizeof(char) * headerData.size(), SEEK_CUR);
    fwrite(data.data(), sizeof(data[0]), data.size(), f);
    
    fclose(f);
}
