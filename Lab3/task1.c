#include <stdio.h>
#define N 51

void main(void)
{
    double step, y, x;
    int i;
    step = 1.0/50;
    for (i = 0; i < N; i++)
    {
        x = 2 + step * i;
        y = fabs(pow(x,2) - 3 * x + 0.1) - exp(x) / (x - 1);
        printf("\nx = %lf y = %lf", x, y);
    }
}
