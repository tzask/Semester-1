#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[256];
    int i;
    int counting_a = 0;
    // name input
    printf ("Enter the full name (with the middle one):\n");
    int n;
    for(n = 0; (name[n] = getchar( ))!='\n'; ++n);
    name[n] = '\0';
    //string length
    int length = strlen(name);
    printf ("\nThe length of our string is %d.\n", length);
    //number of 'a'
    for (i = 0; i < length; i++)
    {
        if (name[i] == 'a' || name[i] == 'A') counting_a++;
    }
    printf ("\nWe have %d 'a' in our string.\n", counting_a);

    //counting the length of every word
    char *pch = strtok (name," ,.");
    int longestword_length = 0;
    char *longestword;
    printf("\nThe longest word:");
    while (pch != NULL) //while we have lexemes
    {
        int wordlen = strlen(pch);
        if (wordlen > longestword_length)
        {
            longestword_length = wordlen;
            longestword = pch;
        }
        pch = strtok (NULL, " ,.-");
    }
    printf("\n%s", longestword);
    return 0;
}
