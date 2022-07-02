#include "../../includes/string.h"

static int	len(long nb)
{
	int		len;

	if (nb == 0)
	{
		len = 1;
		return (len = 1);
	}
	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_malloc(char **str, int i)
{
	(*str) = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	return (*str);
}

char	*itoa(int nb)
{
	char	*str;
	long	n;
	size_t	i;

	n = nb;
	i = len(n);
	str = ft_itoa_malloc(&str, i);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i--] = 48 + (n % 10);
		n = n / 10;
	}
	return (str);
}

bool	_isquote(char c)
{
	if (c == '\'' || c == '"')
		return (true);
	return (false);
}
