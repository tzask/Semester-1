#include <stdio.h>
#include <conio.h>

int main(void)
{
    char x[100], y[3][100], *z;
    int words = 0;
    puts("Enter your string");
    gets(x);
    z = x;
    for(words = 0; *z && words < 3; words++)
    {
        int i;
        for(i = 0; *z != ' ' && *z; z++, i++)y[words][i]=*z;
        y[words][i] = '\0';
        if(*z == ' ') z++;
    }
    if(words == 3 && *z != '\0') puts("You have entered more than three words. They won't be shown.");
    //printing words in inverted order
    int i;
    puts("Your words in inverted order:");
    for(i = words - 1; i >= 0; i--) puts(y[i]);
    return 0;
}
