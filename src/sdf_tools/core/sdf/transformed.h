#pragma once

#include "sdf.h"

#include "operations.h"

#include <memory>

namespace sdf_tools {
namespace sdf {

class SdfTransformed : public Sdf
{
public:
    SdfTransformed(std::shared_ptr<Sdf> sdf,
                   operations::SdfUnaryOperationVar operation);

    real at(real3 r) const override
    {
        const real a = sdf_->at(r);
        return std::visit([a](const auto& op) {return op(a);}, operation_);
    }

private:
    std::shared_ptr<Sdf> sdf_;
    operations::SdfUnaryOperationVar operation_;
};


class SdfComplement : public SdfTransformed
{
public:
    SdfComplement(std::shared_ptr<Sdf> sdf);
};


} // namespace sdf
} // namespace sdf_tools
