#include <stdio.h>
#include <stdlib.h>

#include "variadic.h"

int main() {
    printf("=== Functions ===\n\n");

    printf("Sum (2, 5, 8): %d\n", sum(3, 2, 5, 8));
    printf("Sum (10, 20, 30, 40): %d\n", sum(4, 10, 20, 30, 40));
    printf("Sum (1, 2, 3, 4, 5): %d\n\n", sum(5, 1, 2, 3, 4, 5));

    printf("Max (2, 5, 8): %d\n", max(3, 2, 5, 8));
    printf("Max (10, 20, 30, 40): %d\n", max(4, 10, 20, 30, 40));
    printf("Max (100, 50, 200, 75): %d\n\n", max(4, 100, 50, 200, 75));

    printf("Min (2, 5, 8): %d\n", min(3, 2, 5, 8));
    printf("Min (10, 20, 30, 40): %d\n", min(4, 10, 20, 30, 40));
    printf("Min (100, 50, 200, 75): %d\n\n", min(4, 100, 50, 200, 75));

    printf("Average (2, 5, 8): %.2f\n", average(3, 2, 5, 8));
    printf("Average (10, 20, 30, 40): %.2f\n", average(4, 10, 20, 30, 40));
    printf("Average (1, 2, 3, 4, 5): %.2f\n\n", average(5, 1, 2, 3, 4, 5));

    printf("Average of float (1.5, 2.5, 3.0): %.2f\n", average_float(3, 1.5, 2.5, 3.0));
    return 0;
}
