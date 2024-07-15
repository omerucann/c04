#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int n;

    n = 0;

    if(nb == -2147483648)
    {
        write(1, "-2147483648", 12);

        return ;
    }

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
}

int main()
{
    ft_putnbr(-2147483648);
}