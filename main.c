#include <stdio.h>
#include "triangle.h"

int main() {
    double a, b, c;
    
    printf("Enter three sides of the triangle:\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);
    
    if (check_triangle(a, b, c)) {
        printf("\nPerimeter: %.2lf\n", perimeter(a, b, c));
        printf("Area: %.2lf\n", area(a, b, c));
    } else {
        printf("\nDon't exist\n");
    }
    
    return 0;
}
