#include "printf.h"

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;//1桁分
	else if (n < 0)
	{
		count = 1;//マイナス
		n = -n;//絶対値を取得
	}		
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}



void	ft_putnbr(int n)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (10 <= n)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n < 0)
	{
		if (n == INT_MIN)
			ft_putstr("-2147483648");
		else
		{
			ft_putchar('-');
			ft_putnbr(-n);
		}
	}
}

int	ft_printnbr(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_putnbr(0);
		count = 1;
	}
	else
	{
		ft_putnbr(n);
		count += count_digits(n);
	}
	return (count);
}

