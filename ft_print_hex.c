#include "printf.f"

void	ft_print_hex(unsigned int n, const char format)
{
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			if (format == 'x')
				ft_putchar('a' + (n - 10));
			if (format == 'X')
				ft_putchar('A' + (n - 10));
		}
	}
	else
	{
		ft_print_hex(n / 16);
		ft_print_hex(n % 16);
	}
}					
