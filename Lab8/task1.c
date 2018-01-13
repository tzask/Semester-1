#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100

struct STGROUP
    {
        char surname[MAX];
        double marks_average;
    };

int main(void)
{
    struct STGROUP student [MAX];

    FILE* list = fopen ("listofstudents.txt", "r");
    char line[256];
    int n = 0;

    while (fgets(line, sizeof(line), list))//reading one line
    {
        int i = 0;
        int sum = 0;
        int marks_number = 0;
        int mark = 0;
        do // reding a surname until first '\t' or ' '
        {
            student[n].surname[i] = line [i];
            i++;
        } while (student[n].surname[i - 1] != '\t' &&
                 student[n].surname[i - 1] != ' ');

        student[n].surname[i-1] = '\0';

        char temp[3];
        int j = 0;
        i--;

        do // reading marks
        {
            i++;
            if (line[i] > 47 && line[i] < 58)
            {
                temp[j] = line[i];
                j++;
            }
            if (line[i] == ' ' ||
                line[i] == '\t' ||
                line[i] == '\n' ||
                line[i] == '\0')
            {
                mark = atoi(temp); // char into int type conversion
                sum += mark;
                if (mark != 0) marks_number++;
                temp[0] = temp[1] = temp[2] = '\0';
                j = 0;
            }

        }while (line [i] != '\n' && line [i] != '\0' );

        student[n].marks_average = (double) sum / marks_number; // reading student's marks_average
        n++;
    }

    fclose(list);

    int k;
    double group_sum;
    double grMarks_average;
    for (k = 0; k < n; k++) group_sum += student[k].marks_average; // total sum of marks of all students
    grMarks_average = group_sum / n; // marks average of all students
    printf("Average of marks of the group: %lf.\n" , grMarks_average);
    printf("List of students that have the average of their marks more than group's average:\n");
    for (k = 0; k < n; k++)
    {
        if (student[k].marks_average > grMarks_average)
        printf("%s\t%lf\n", student[k].surname, student[k].marks_average);
    }
    return 0;
}
