#pragma once

#include "sdf.h"

#include "operations.h"

#include <memory>

namespace sdf_tools {
namespace sdf {

class SdfComposed : public Sdf
{
public:
    SdfComposed(std::unique_ptr<Sdf> sdfA,
                std::unique_ptr<Sdf> sdfB,
                operations::SdfBinaryOperationVar operation);

    real at(real3 r) const override
    {
        const real a = sdfA_->at(r);
        const real b = sdfB_->at(r);
        return std::visit([a,b](const auto& op) {return op(a,b);}, operation_);
    }

private:
    std::unique_ptr<Sdf> sdfA_;
    std::unique_ptr<Sdf> sdfB_;
    operations::SdfBinaryOperationVar operation_;
};

} // namespace sdf
} // namespace sdf_tools
