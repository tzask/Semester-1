#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[51]; // +1 symbol for '\0'
    int i;
    int counting_a = 0;
    // string input
    printf ("Enter the string:\n");
    int n;
    for(n = 0; (name[n] = getchar( ))!='\n'; ++n);
    name[n] = '\0';
    //words starting with 'i' and 'h'
    printf("\nAll words starting with 'i' or 'h':\n");
    char *printedword = strtok (name," ,.");
    while (printedword != NULL) //while we have lexemes
    {
        if (printedword[0] == 'i' || printedword[0] == 'I' ||
            printedword[0] == 'h' || printedword[0] == 'H')
        {
            printf("\n%s", printedword);
        }
        printedword = strtok (NULL, " ,.-");
    }
    return 0;
}
