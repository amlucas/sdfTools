#pragma once

#include "sdf.h"

#include <sdf_tools/core/types.h>

#include <vector>

namespace sdf_tools {
namespace sdf {

class SdfFromMesh : public Sdf
{
public:
    SdfFromMesh(std::vector<int3> faces, std::vector<real3> vertices, bool inside);

    real at(real3 r) const override;

private:
    std::vector<int3> faces_;
    std::vector<real3> vertices_;
    int sign_;
};

} // namespace sdf
} // namespace sdf_tools
