#include <stdio.h>
#include "variadic.h"

int main() {
    int count = 3;
    int a = sum(count, 0, 5, 10);
    int b = max(count, 0, 5, 10);
    int c = min(count, 0, 5, 10);
    double d = average(count, 0, 5, 10);
    
    printf("%d %d %d %.2f\n", a, b, c, d);
    return 0;
}
