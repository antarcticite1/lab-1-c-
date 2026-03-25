#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_triangle_valid(double a, double b, double c) {
    return (a > 0 && b > 0 && c > 0) &&
           (a + b > c) &&
           (a + c > b) &&
           (b + c > a);
}

double calculate_perimeter(double a, double b, double c) {
    return a + b + c;
}

double calculate_area(double a, double b, double c) {
    double s = calculate_perimeter(a, b, c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    double a, b, c;

    printf("Enter the length of the sides of the triangle:\n");
    printf("Side a: ");
    scanf("%lf", &a);
    printf("Side b: ");
    scanf("%lf", &b);
    printf("Side c: ");
    scanf("%lf", &c);

    if (!is_triangle_valid(a, b, c)) {
        printf("Don't exist!\n");
        return 1;
    }

    double perimeter = calculate_perimeter(a, b, c);
    double area = calculate_area(a, b, c);

    printf("\nPerimeter: %.2lf\n", perimeter);
    printf("Area: %.2lf\n", area);

    return 0;
}
