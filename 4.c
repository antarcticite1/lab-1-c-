#include <stdio.h>
#include "triangle.h"

int main() {
    double a, b, c;
    
    printf("Enter the lenght of the sides of the triangle:\n");
    printf("Side a: ");
    scanf("%lf", &a);
    printf("Side b: ");
    scanf("%lf", &b);
    printf("Side c: ");
    scanf("%lf", &c);
    
    bool is_triangle_valid(double a, double b, double c) {
    return (a > 0 && b > 0 && c > 0) && 
           (a + b > c) && 
           (a + c > b) && 
           (b + c > a);
        if (!its_valid_triangle(a, b, c)) {
        printf("Don't exist!\n");
        return 1;
    }
}

    double perimeter = calculate_perimeter(a, b, c);
    double area = calculate_area(a, b, c);
    
    printf("\nPerimeter?: %.2lf\n", perimeter);
    printf("\nArea: %.2lf\n", area);
    
    return 0;
}
