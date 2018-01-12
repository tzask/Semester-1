#include <stdio.h>

void main(void)
{
    double x, y;
    printf("Enter x:");
    scanf("%lf", &x); //x=2.6
    y = 1 + x - (pow(x,2)/2) +(pow(x,3)/6);
    printf("\nif x = %lf, then y=%lf", x, y);
}
