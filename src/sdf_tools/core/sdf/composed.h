#pragma once

#include "sdf.h"

#include "operations.h"

#include <memory>

namespace sdf_tools {
namespace sdf {

class SdfComposed : public Sdf
{
public:
    SdfComposed(std::shared_ptr<Sdf> sdfA,
                std::shared_ptr<Sdf> sdfB,
                operations::SdfBinaryOperationVar operation);

    real at(real3 r) const override
    {
        const real a = sdfA_->at(r);
        const real b = sdfB_->at(r);
        return std::visit([a,b](const auto& op) {return op(a,b);}, operation_);
    }

private:
    std::shared_ptr<Sdf> sdfA_;
    std::shared_ptr<Sdf> sdfB_;
    operations::SdfBinaryOperationVar operation_;
};

class SdfUnion : public SdfComposed
{
public:
    SdfUnion(std::shared_ptr<Sdf> sdfA,
             std::shared_ptr<Sdf> sdfB);
};

class SdfIntersection : public SdfComposed
{
public:
    SdfIntersection(std::shared_ptr<Sdf> sdfA,
                    std::shared_ptr<Sdf> sdfB);
};

class SdfDifference : public SdfComposed
{
public:
    SdfDifference(std::shared_ptr<Sdf> sdfA,
                  std::shared_ptr<Sdf> sdfB);
};

class SdfSmoothUnion : public SdfComposed
{
public:
    SdfSmoothUnion(std::shared_ptr<Sdf> sdfA,
                   std::shared_ptr<Sdf> sdfB,
                   real k);
};

} // namespace sdf
} // namespace sdf_tools
