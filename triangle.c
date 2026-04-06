#include <math.h>
#include "triangle.h"
#include <stdbool.h>

bool check_triangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double perimeter(double a, double b, double c) {
    return a + b + c;
}

double area(double a, double b, double c) {
    double p = perimeter(a, b, c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
