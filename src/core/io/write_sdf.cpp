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
    std::string fname = basename + ext;
    
    FILE *f = safeOpen(fname.c_str(), "wb");

    std::stringstream ss;

    auto h = grid->getSpacing();
    auto n = grid->getDimensions();
    auto data = getFloatData(grid);
        
    ss << h.x << ' ' << h.y << ' ' << h.z << '\n';
    ss << n.x << ' ' << n.y << ' ' << n.z << '\n';

    std::string headerData = ss.str();

    fwrite(headerData.c_str(), sizeof(char), headerData.size(), f);
    fseek(f, sizeof(char) * headerData.size(), SEEK_CUR);
    fwrite(data.data(), sizeof(data[0]), data.size(), f);
    
    fclose(f);
}
