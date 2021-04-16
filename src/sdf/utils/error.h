#pragma once

#include <cstdio>
#include <cstdlib>

#define STRINGIZE(x) STRINGIZE2(x)
#define STRINGIZE2(x) #x

#define error(...) do {                                                 \
    fprintf(stderr, __FILE__ ":" STRINGIZE(__LINE__) ": "               \
            __VA_ARGS__);                                               \
    exit(1);                                                            \
    } while (0) 
