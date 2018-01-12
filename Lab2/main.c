#include <stdio.h>
#define K 4.37
#define L 3.15

void main(void)
{
    double xi, y, t1, t2, pow_y;
    double x[3];
    long i;
    for (i = 0; i < 3; i++)
    {
        printf("\nEnter x_%d =", i+1);
        scanf("%lf", &x[i]); //x1=-1.427, x2=0.525, x3=8.341
        xi = x[i];
        if (xi >= 0)
        {
            t1 = cos(xi)/(K - sqrt(xi)) + sin(xi)/(L + sqrt(xi));
            printf("\nt1 = %lf", t1);
            if (xi >= -0.5 && xi <= 0.5)
            {
                t2 = 2 * (asin(2*xi) + L);
                printf("\nt2 = %lf", t2);
                //calculating y
                if (fabs(t1) < 2 * fabs(t2))
                {
                    pow_y = 3 * t1 - 4 * t2;
                    if (pow_y >= 0)
                    {
                        y = sqrt(3 * t1 - 4 * t2);
                        printf("\ny = %lf", y);
                    }
                    else printf("\nWe cannot extract the square root of the negative number %lf\n", pow_y);
                }
                else { y = sqrt(3 * t1 + 4 * t2); printf("\ny = %lf", y);}
            }
            else printf("\nEnter x that is >= -0.5 and <= 0.5, because we use asin(2*x) for x\n");
        }
        else printf("\nEnter  x that is more or equal 0, because we use sqrt() for x\n");
    }
}
