#include <stdio.h>

int main(void)
{
    char    *string;
    int     i;
    int     j;
    string = "abcabcabcabcabcabccccc";
    i = 0;
    j = 0;
    while (string[i])
    {
        if (string[i] == 'c')
        {
            j++;
            printf("%d ", j);
        }
        i++;
    }
    return (0);
}