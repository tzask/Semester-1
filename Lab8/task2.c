#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100

struct MEDCARD
{
    char surname[MAX];
    char name[MAX];
    char sex;
    int height;
    int weight;
};

int main(void)
{
    struct MEDCARD student [MAX];

    FILE* list = fopen ("medcards.txt", "r");
    char line[256];
    /*
    while (fgets(line, sizeof(line), list))//reading one line
    {
        printf("%s", line);
    }
    fseek(list, 0, SEEK_SET);//putting cursor onto the beginning of the file
    */

    int n = 0;
    while (fgets(line, sizeof(line), list))//reading one line
    {
        int i = 0;
        do / reding a surname until first '\t' or ' '
        {
            student[n].surname[i] = line [i];
            i++;
        } while (student[n].surname[i - 1] != '\t' &&
                 student[n].surname[i - 1] != ' ');
        student[n].surname[i - 1] = '\0';
        while (line[i] == '\t' || // putting line[i] onto the position of the next first letter
               line[i] == ' ') i++;

        int j = 0;
        do // // reding a name until first '\t' or ' '
        {
            student[n].name[j] = line [i];
            j++;
            i++;
        } while (student[n].name[j - 1] != '\t' &&
                 student[n].name[j - 1] != ' ');

        student[n].name[j - 1] = '\0';

        while (line[i] == '\t' || // putting line[i] onto the position of the next first letter
               line[i] == ' ') i++;

        student[n].sex = line[i];
        i++;

        while (line[i] == '\t' || // putting line[i] onto the position of the next first number
               line[i] == ' ') i++;
        i--;
        char temp[4];
        j = 0;
        int height_weight = 0;//decides where to write the number

        do // reading height and weight
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
                if(height_weight == 0)
                {
                    student[n].height = atoi(temp); // char into int type conversion
                    height_weight++;
                }
                else student[n].weight = (double)atoi(temp); // char into double type conversion
                temp[0] = temp[1] = temp[2] = '\0';
                j = 0;
            }
        } while (line [i] != '\n' && line [i] != '\0' );
        n++;
    }
    fclose(list);
    // medcards input
    int i;
    for (i = 0; i < n; i++) // n - число студентов
    {
        printf("Student: %s %s\n", student[i].surname, student[i].name);
        if (student[i].sex == 'f') printf("\t sex: female\n");
        else printf("\t sex: male\n");
        printf("\t height: %d\n\t weight: %d\n\n", student[i].height, student[i].weight);
    }
    // reading average height and weight (m)
    double average_height, average_weight;
    int sum_height = 0;
    int sum_weight = 0;
    int male = 0;

    for (i = 0; i < n; i++)
    {
        if (student[i].sex == 'm')
        {
            sum_height += student[i].height;
            sum_weight += student[i].weight;
            male++;
        }
    }

    average_height = (double) sum_height / (double) male;
    average_weight = (double) sum_weight / (double) male;

    printf("Average height of male students: %lf.\n" , average_height);
    printf("Average weight of male students: %lf.\n" , average_weight);

    return 0;
}
