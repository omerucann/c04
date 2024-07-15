#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;

    while(str[i])
    {
        i++;
    }
    return (i);
}

int main()
{
    char a[] = "Merhaba";

    int b = ft_strlen(a);

    printf("%d", b);
}