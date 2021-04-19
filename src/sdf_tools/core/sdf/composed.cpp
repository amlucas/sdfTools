#include "composed.h"

namespace sdf_tools {
namespace sdf {

SdfComposed::SdfComposed(std::shared_ptr<Sdf> sdfA,
                         std::shared_ptr<Sdf> sdfB,
                         operations::SdfBinaryOperationVar operation) :
    sdfA_(std::move(sdfA)),
    sdfB_(std::move(sdfB)),
    operation_(std::move(operation))
{}


SdfUnion::SdfUnion(std::shared_ptr<Sdf> sdfA,
                   std::shared_ptr<Sdf> sdfB) :
    SdfComposed(std::move(sdfA),
                std::move(sdfB),
                operations::Union{})
{}

SdfIntersection::SdfIntersection(std::shared_ptr<Sdf> sdfA,
                                 std::shared_ptr<Sdf> sdfB):
    SdfComposed(std::move(sdfA),
                std::move(sdfB),
                operations::Intersection{})
{}


SdfDifference::SdfDifference(std::shared_ptr<Sdf> sdfA,
                             std::shared_ptr<Sdf> sdfB) :
    SdfComposed(std::move(sdfA),
                std::move(sdfB),
                operations::Difference{})
{}


} // namespace sdf
} // namespace sdf_tools
