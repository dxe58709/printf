#include "printf.h"

int	count_udigits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;//1桁分
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	ft_putunbr(unsigned int n)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (10 <= n)
	{
		ft_putunbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

int	ft_printunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_putunbr(0);
		count = 1;
	}
	else
	{
		ft_putunbr(n);
		count += count_udigits(n);
	}
	return (count);
}

