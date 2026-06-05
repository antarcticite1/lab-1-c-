#include <stdio.h>
#include <stdarg.h>
#include "variadic.h"

int sum(int count, ...) {
    va_list args;
    int total = 0;
    
    va_start(args, count);
    for(int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);
    
    return total;
}

int max(int count, ...) {
    va_list args;
    int maximum;
    
    va_start(args, count);
    maximum = va_arg(args, int);
    
    for(int i = 1; i < count; i++) {
        int current = va_arg(args, int);
        if(current > maximum) {
            maximum = current;
        }
    }
    va_end(args);
    
    return maximum;
}

int min(int count, ...) {
    va_list args;
    int minimum;
    
    va_start(args, count);
    minimum = va_arg(args, int);
    
    for(int i = 1; i < count; i++) {
        int current = va_arg(args, int);
        if(current < minimum) {
            minimum = current;
        }
    }
    va_end(args);
    
    return minimum;
}

double average(int count, ...) {
    va_list args;
    int total = 0;
    
    va_start(args, count);
    for(int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);
    
    return (double)total / count;
}
