#include "error.h"

#include "strprintf.h"

#include <iostream>
#include <stdarg.h>

namespace sdf_tools
{
void die(const char *file, int line, const char* pattern, ...)
{
    std::string errMsg = utils::strprintf("[sdf_tools] %s:%d:\n", file, line);

    va_list args;
    va_start(args, pattern);
    errMsg += utils::vstrprintf(pattern, args);
    va_end(args);

    throw std::runtime_error(errMsg);
}

} // namespace sdf_tools
