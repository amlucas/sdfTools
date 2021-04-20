#include "strprintf.h"

#include <cstdio>

namespace sdf_tools {
namespace utils {

std::string vstrprintf(const char *fmt, va_list args)
{
    va_list args2;
    va_copy(args2, args);

    const int size = vsnprintf(nullptr, 0, fmt, args);

    std::string result(size, '_');
    vsnprintf(&result[0], size + 1, fmt, args2);
    return result;
}

std::string strprintf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    const std::string result = vstrprintf(fmt, args);
    va_end(args);
    return result;
}

} // namespace utils
} // namespace sdf_tools
