#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		else if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

static	char	*reverser(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
	return (s);
}

static int	nbrcounter(int n)
{
	int	counter;

	counter = 0;
	if (n < 0 || n == 0)
	{
		counter += 1;
	}
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*ntostr;
	int		nbrlen;
	long	cast;
	int		i;

	i = 0;
	cast = (long)n;
	nbrlen = nbrcounter(cast);
	ntostr = malloc(nbrlen + 1);
	if (!ntostr)
		return (NULL);
	if (cast < 0)
	{
		ntostr[nbrlen - 1] = '-';
		cast *= (-1);
	}
	if (cast == 0)
		ntostr[nbrlen - 1] = '0';
	while (cast != 0)
	{
		ntostr[i++] = (cast % 10) + 48;
		cast /= 10;
	}
	ntostr[nbrlen] = '\0';
	return (reverser(ntostr));
}