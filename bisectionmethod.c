#include <stdio.h>
#include<conio.h>
#include <math.h>

double func(double x) {
    // Defining the function
    return x*sin(x)+cos(x);
}

double bisection(double a, double b, double epsilon) {
    double c;
    int iterations = 0;

    printf("Iteration\t   a\t\t   b\t\t   c\t\t   f(c)\n");

    while (1) {
        c = (a + b) / 2.0;

        printf("%8d\t%10.6f\t%10.6f\t%10.6f\t%10.6f\n", iterations, a, b, c, func(c));

        if (func(c) == 0.0 || fabs(b - a) < epsilon) {
            break;
        } 
		 if (func(c) * func(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iterations++;
        
        if (iterations > 100) {
            printf("Maximum iterations exceeded.\n");
            break;
        }
    }

    printf("\n\nSubash Khanal\n CRN:(020-626)\n\n");

    return c;
}

int main() {
    double a, b, epsilon;
    double root;
     printf("Enter the value of a:");
    scanf("%lf",&a);
    printf("Enter the value of b:");
    scanf("%lf",&b);
    epsilon = 0.00001; 

    // Call the bisection method
    root = bisection(a, b, epsilon);
    printf("Approximate root: %lf\n", root);

    return 0;
    getch();
}
                            
     
