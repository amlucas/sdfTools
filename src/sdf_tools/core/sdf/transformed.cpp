#include "transformed.h"

namespace sdf_tools {
namespace sdf {

SdfTransformed::SdfTransformed(std::shared_ptr<Sdf> sdf,
                               operations::SdfUnaryOperationVar operation) :
    sdf_(std::move(sdf)),
    operation_(std::move(operation))
{}


SdfComplement::SdfComplement(std::shared_ptr<Sdf> sdf) :
    SdfTransformed(std::move(sdf), operations::Complement{})
{}


} // namespace sdf
} // namespace sdf_tools
