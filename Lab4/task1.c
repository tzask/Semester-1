#include <stdio.h>

int main (void)
{
    FILE *matrix_file;

    float matrix [8][8];
    int j, i;
    matrix_file = fopen("matrix77.txt", "w");

    for(j = 1; j < 8; j++) //a_1j
        {
            matrix [1][j] = 2.0 * j + 3.0;
            fprintf(matrix_file, "%f\t", matrix [1][j]);
        }
        fprintf(matrix_file, "\n");

    for(j = 1; j < 8; j++) //a_2j
        {
            matrix [2][j] = j - 3.0 / (2.0 + 1.0 / j);
            fprintf(matrix_file, "%f\t", matrix [2][j]);
        }
        fprintf(matrix_file, "\n");

    for(i = 3; i < 8; i++)
        {
            for(j = 1; j < 8; j++)
            {
                matrix [i][j] = matrix [i - 1][j] + matrix [i - 2][j];
                fprintf(matrix_file, "%f\t", matrix [i][j]);
            }
            fprintf(matrix_file, "\n");
        }
    fclose(matrix_file);
    return 0;
}
