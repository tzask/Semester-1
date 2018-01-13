#include <stdio.h>
#define MAX 30
double min (double *t);
double max (double *t);
double min_two (double *t, double *r);
double max_two (double *t, double *r);

int main(void)
{
    double A[MAX], B[MAX], C[MAX];
    srand ( time(NULL) );
    int i;
        for(i = 0; i < MAX; i++)
        {
            A[i] = rand() % 100 + 1;  //[min;max]y=rand()%(max-min+1)+min;
            B[i] = rand() % 100 + 1;
            C[i] = rand() % 100 + 1;
        }
	double t;
	if (min(A) < max(B))  t = min(B) / max(A) + max(C) / min_two(B, C);
	else t = max_two(B, C) + min(C);

	printf("A:\n");
	for (i = 0; i < MAX; i++) printf(" %5.0lf;", A[i]);
	printf("\nB:\n");
	for (i = 0; i < MAX; i++) printf(" %5.0lf;", B[i]);
	printf("\nC:\n");
	for (i = 0; i < MAX; i++) printf(" %5.0lf;", C[i]);
	printf("\n\nt = %lf", t);
	return 0;
}
double min (double *t)
{
	int i = 0;
	double min = t[i];
	for (i = 0; i < MAX; i++)
	{
		if (t[i] < min) min = t[i];
	}
	return min;
}
double max (double *t)
{
	int i = 0;
	double max  = t[i];
	for (i = 0; i < MAX; i++)
	{
		if (t[i] > max) max = t[i];
	}
	return max;
}
double min_two (double *t, double *r)
{
	int i = 0;
	double together[MAX];
	for (i = 0; i < MAX; i++)
	{
		together[i] = t[i] + r[i];
	}
	double min = together[i];
	for (i = 0; i < MAX; i++)
	{
		if (together[i] < min) min = together[i];
	}
	return min;
}
double max_two (double *t, double *r)
{
	int i = 0;
	double together[MAX];
	for (i = 0; i < MAX; i++)
	{
		together[i] = t[i] + r[i];
	}
	double max = together[i];
	for (i = 0; i < MAX - 1; i++)
	{
		if (together[i] > max) max = together[i];
	}
	return max;
}
