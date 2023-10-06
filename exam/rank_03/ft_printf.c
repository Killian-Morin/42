#include <stdarg.h>
#include <unistd.h>

/*
	PASSE grademe
*/

void	printf_string(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)//change the string if is null
		s = "(null)";
	while (s[i])
		*len += write(1, &s[i++], 1);//write the current char, then increase the string while using the return of write() to increase len
}

void	printf_chiffre(long long int n, int base, int *len)
{
	char	*cara;

	cara = "0123456789abcdef";//the char that can be used for the print, for the base 10 it will not exceed the digit
	if (n < 0)//for the negative it convert them to positive and write the ‘-’
	{
		*len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= base)//recursive to wait for a valid char that will be present in the available string of char
		printf_chiffre((n / base), base, len);
	*len += write(1, &cara[n % base], 1);//write the current char using the string of available char and the index of this current char in the string, while using the return value of write() to increase len
}

int ft_printf(const char *s, ... )
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, s);
	while (*s)
	{
		if (*s == '%' && ((*(s + 1) == 's') || *(s + 1) == 'd' || *(s + 1) == 'x'))
		{
			s++;//iterate to see the type of the print
			//send the address of len to iterate it in those function, it is return at the end
			if (*s == 's')
				printf_string(va_arg(arg, char *), &len);
			else if (*s == 'd')
				printf_chiffre((long long int)va_arg(arg, int), 10, &len);//base 10
			else if (*s == 'x')
				printf_chiffre((long long int)va_arg(arg, unsigned int), 16, &len);//base 16
		}
		else
			len += write(1, s, 1);//write the other char not concerning the print
		s++;
	}
	va_end(arg);
	return (len);
}

/*
#include <stdio.h>
#include <limits.h>
int main(void)
{
	int	i, j, k;

	i = ft_printf("%s", "bonjour");
	printf("\t%d\n", i);
	j = ft_printf("%d", 19);
	printf("\t%d\n", j);
	k = ft_printf("%x", 1321);
	printf("\t%d\n", k);
	return (0);
}*/
