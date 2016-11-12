//
// Created by alexey on 19.10.16.

#ifndef LINUX_SYSTEM_PROGRAMMING_SOLUTION_C
#define LINUX_SYSTEM_PROGRAMMING_SOLUTION_C

//
#include "stddef.h"
#include "string.h"
//extern "C"
int stringStat(const char *string, size_t multiplier, int *count) {
    size_t result =strlen(string);
    (*count)++;
    result =  (int)(result *  multiplier );
    return  result;
}
#endif //LINUX_SYSTEM_PROGRAMMING_SOLUTION_C


