#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

static double
modified_fact (int n)
{
        if (n == 0) return 1;
        else
        {
            double result = 1;
            int i;
            for (i = 1; i <= n; i++)
            {
                double di = i;
                result = result * ((n + di) / (4.0 * di));
            }
            return result;
        }}

int
main (void)
{
    double x, exact_arccos, appr_arccos, sum, error, all_sum;
    int n;

    printf("\nEnter x = ");
    scanf("%lf", &x);

    exact_arccos = acos(x);
    printf("\nExact value of arccos(x) = %lf", exact_arccos);

    n = 0;
    do {
            sum = (modified_fact (n) / (2 * n + 1)) * pow(x, 2 * n + 1);
            all_sum += sum;
            n++;
        } while (sum > 0.0001);

    appr_arccos = M_PI / 2 - all_sum;
    printf("\nApproximate value of arccos(x) = %lf", appr_arccos);
    error = fabs(exact_arccos - appr_arccos);
    printf("\nError of the measurement= %lf", error);
  return 0;
}
