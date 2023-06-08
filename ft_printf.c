#include "printf.h"

void	my_printf(const char *fmt, ...)
{
	ssize_t	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			


int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	va_start(ap, fmt);
	va_end(ap);
	return ();
}
