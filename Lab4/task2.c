#include <stdio.h>
#include <stdlib.h>
#define ARR_LENGTH 25

int main (void)
{
    int array [ARR_LENGTH];
    int i, j;
    char choice;

    //menu for choosing how you'd like enter your array
    printf("Choose the way you want to fill in the array[25]:\n");
    printf("Press 'f' if you want to take an array from a file.\n");
    printf("Press 'w' if you want to write an array by yourself.\n");
    printf("Press 'r' if you want to make a random array.\n");
    scanf("%c", &choice);
    switch ( choice )
    {
    case 'f': //reading from the file
    {
        char file_name[100];
        printf("\nEnter file's name from program's directory:\n");
        scanf ("%s", file_name);
        for ( i = 0; i < 100; i++ )
        {
            if ( file_name[i] == '\n' )
            {
                file_name[i] = '\0';
                break;
            }
        }
        printf("\nFile's name:\n%s", file_name);
        FILE *array_file;
        array_file = fopen (file_name, "r");
        for(i = 0; i < ARR_LENGTH; i++)
        {
            fscanf(array_file, "%d", &array[i]);
        }
        fclose (array_file);
    }
    break;
    case 'w': // keyboard input
    {
        printf("\n\nEnter array[25] with values in the range [-8; 15]\n");
        for(i = 0; i < ARR_LENGTH; i++)
        {
            scanf("%d", &array[i]);
            while (array[i] < -8 || array[i] > 15)
            {
                printf("\nError! Enter value in the range [-8; 15]\n");
                scanf("%d", &array[i]);
            }
        }
    }
    break;
    case 'r': //random array
    {
        srand ( time(NULL) );
        for(i = 0; i < ARR_LENGTH; i++)
        {
            array[i] = -8 + rand() % 24; //[min;max]y=rand()%(max-min+1)+min;
        }
    }
    break;
    default: printf("\nError! There's no such a choice.\n");
             return 0;
    }
        //output
        printf("\nOur array:\n");
        for(i = 0; i < ARR_LENGTH; i++)
        {
            printf("%d ", array [i]);
        }
        //linear search
        int element, no_element;
        no_element = 0;
        printf("\n\nEnter the element you want to find in this array:\n");
        scanf ("%d", &element);
        for ( i = 0; i < ARR_LENGTH; i++ )
        {
            if ( array [i] == element )
            {
                printf("\nWe have found the element %d on the position %d", element, i);
                no_element ++;
            }
        }
        //result check
        if (no_element == 0)
        {
            printf("\n\nThe search is finished. Sorry, we haven't found any matching elements.\n");
        } else printf("\n\nThe search is finished. We have found %d matching element(s).\n", no_element);

        //changing the array according to the task
        printf("\n\nNow we will change this array according to our task:\n");

        int fi, // forward index
            bi, // backward index
            fi_found, bi_found;
        fi = 0;
        bi = ARR_LENGTH - 1;

        if (array[fi] >= 0) fi_found = 1;
        else fi_found = 0;

        if (array[bi] >= 0) bi_found = 1;
        else bi_found = 0;

        while (fi != bi)
        {
            if (fi_found == 0)
            {
                fi++;
                if (array[fi] >= 0) fi_found = 1;
            }
            else if (bi_found == 0)
            {
                bi--;
                if (array[bi] >= 0) bi_found = 1;
            }
            if (fi_found == 1 && bi_found == 1 && fi != bi)
            {
                int temp = array[fi];
                array[fi] = array[bi];
                array[bi] = temp;
                fi_found = 0;
                bi_found = 0;
            }
        }

        //output
        printf("\nOur changed array:\n");
        for(i = 0; i < ARR_LENGTH; i++) printf("%d ", array [i]);

        //bubble sort
        printf("\n\nNow we will sort this array (bubble sort).\n");
        for(i = 0 ; i < ARR_LENGTH - 1; i++)
        {
            // compare to elements
            for(j = 0 ; j < ARR_LENGTH - i - 1 ; j++)
            {
                if(array[j] > array[j+1])
                {
                    // swap
                    int tmp = array[j];
                    array[j] = array[j+1] ;
                    array[j+1] = tmp;
                }
            }
        }
        //output
        printf("\nOur sorted array:\n");
        for(i = 0; i < ARR_LENGTH; i++) printf("%d ", array [i]);
    return 0;
}
