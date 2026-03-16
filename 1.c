#include <stdio.h>
#include <math.h>

int main()
{
	
	double a, b, c;
	double x1, x2;
	double discriminant;
	int cont = 1;
	
	while (cont == 1){
		
		printf("a: ");
		scanf("%lf",&a );
		printf("b: ");
		scanf("%lf",&b );
		printf("c: ");
		scanf("%lf",&c );
		
		
		discriminant = (pow(b, 2) - 4*a*c);
		if (discriminant > 0){
			x1 = (-b + sqrt(discriminant)) / (2*a);
			x2 = (-b - sqrt(discriminant)) / (2*a);
				printf("x1 = %f\n", x1);
				printf("x2 = %f\n", x2);
		}
		
		if (discriminant < 0) {
			printf("Don't exist'");
			printf("====================================\n");
			printf("\nContinue? (1 - yes, 0 -no): \n");
			scanf("%d", &cont);
			if (cont != 1) {
				printf("stop");
			}
		}
	}
}
