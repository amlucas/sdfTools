#pragma once

#include <sdf_tools/core/types.h>

namespace sdf_tools {
namespace sdf {

class Sdf
{
public:
    virtual ~Sdf() = default;
    virtual real at(real3 r) const = 0;
};

} // namespace sdf
} // namespace sdf_tools
