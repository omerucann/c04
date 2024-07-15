#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int is_valid_base(char *base)
{
    int i, j;

    i = 0;
    while (base[i])
    {
        if (base[i] == '+' || base[i] == '-' || base[i] == ' '
            || (base[i] >= '\t' && base[i] <= '\r'))
            return (0);
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (i > 1); // Tabanın en az 2 karakterden oluşması gerektiği kontrolü
}

void ft_putnbr_base(int nbr, char *base)
{
    unsigned int size;
    unsigned int n;

    size = 0;
    while (base[size])
        size++;
    if (!is_valid_base(base) || size < 2)
        return ;
    if (nbr < 0)
    {
        ft_putchar('-');
        n = -nbr;
    }
    else
    {
        n = nbr;
    }
    if (n >= size)
    {
        ft_putnbr_base(n / size, base);
        n %= size;
    }
    ft_putchar(base[n]);
}


void ft_putnbr_base(int nbr, char *base);

int main() {
    // Test cases
   
    ft_putnbr_base(123, "0123456789");
    
    ft_putnbr_base(-456, "0123456789");
   

   
    return 0;
}
