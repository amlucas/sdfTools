// Copyright 2020 ETH Zurich. All Rights Reserved.
#pragma once

#include <cstdio>
#include <iostream>
#include <string>

namespace sdf_tools
{
void die [[gnu::format(printf, 3, 4)]] (const char *file, int line, const char* pattern, ...);
} // namespace sdf_tools

#define SDF_TOOLS_ASSERT(val, pattern, ...) do {                        \
        if (!(val)) {                                                   \
            sdf_tools::die(__FILE__, __LINE__, pattern, ##__VA_ARGS__); \
        }                                                               \
    } while(0)


#define sdfToolsExpect(val, pattern, ...) SDF_TOOLS_ASSERT(val, pattern, ##__VA_ARGS__)
#define sdfToolsEnsure(val, pattern, ...) SDF_TOOLS_ASSERT(val, pattern, ##__VA_ARGS__)

#define sdfToolsDie(pattern, ...) sdf_tools::die(__FILE__, __LINE__, pattern, ##__VA_ARGS__)
