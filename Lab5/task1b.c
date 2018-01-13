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
    int letters = 0;
    int words = 0;
    int word_1Length, word_2Length, word_3Length;
    for (i = 0; i < length + 1; i++)
    {
        if ((name[i] > 64 && name[i] < 91) ||
            (name[i] > 96 && name[i] < 123))
            {
                letters++;
            }
        else if (name[i] == ' ' || name[i] == '\0')
        {
            switch (words)
            {
                case 0: word_1Length = letters; words++; break;
                case 1: word_2Length = letters; words++; break;
                case 2: word_3Length = letters; words++; break;
            }
            letters = 0;
        }
    }

    //the longest word
    int longest_word;

    if (word_1Length == word_2Length ||
        word_2Length == word_3Length ||
        word_3Length == word_1Length)
    {
        printf ("\nError! We don't have the longest word (there are two or more of them).\n");
    }
    else
    {
        if (word_1Length > word_2Length)
        {
            longest_word = word_1Length;
        } else longest_word = word_2Length;
        if (longest_word < word_3Length)
        {
            longest_word = word_3Length;
        }
        printf ("\nThe longest word:\n");
        //the longest word output
        if (longest_word == word_1Length)
        {
            for (i = 0; i < word_1Length + 1; i++)
            {
                printf ("%c", name[i]);
            }
        }
        if (longest_word == word_2Length)
        {
            for (i = word_1Length + 2; i < word_1Length + 2 + word_2Length; i++)
            {
                printf ("%c", name[i]);
            }
        }
        if (longest_word == word_3Length)
        {
            for (i = word_1Length + word_2Length + 3;
                 i < word_1Length + word_2Length + word_3Length + 3;
                 i++)
            {
                printf ("%c", name[i]);
            }
        }
    }
    return 0;
}
