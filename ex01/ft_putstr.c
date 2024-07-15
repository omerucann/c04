#include <unistd.h>

int ft_strlen(char *str)
{
    int length = 0;
    
    while (*str != '\0') 
    { 
        length++;
        str++;
    }
    
    return length;
}
void ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}


int main()
{
    char str[] = "Omer";

    ft_putstr(str);

    return 0;
}