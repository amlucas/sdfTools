#include "composed.h"

namespace sdf_tools {
namespace sdf {

SdfComposed::SdfComposed(std::unique_ptr<Sdf> sdfA,
                         std::unique_ptr<Sdf> sdfB,
                         operations::SdfBinaryOperationVar operation) :
    sdfA_(std::move(sdfA)),
    sdfB_(std::move(sdfB)),
    operation_(std::move(operation))
{}

} // namespace sdf
} // namespace sdf_tools
