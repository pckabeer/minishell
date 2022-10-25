#include "minishell.h"

void	ft_putchar_fd(char c,int fd)
{
	write(1, &c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		write(1, "-", fd);
		num = -n;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, 1);
	ft_putchar_fd(num % 10 + '0', 1);
}

void	ft_putstr_fd(char *s,int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], fd);
		i++;
	}
	write(1, "\n", fd);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	if (num >= 2147483648 && sign == 1)
		return (-1);
	else if (num > 2147483648 && sign == -1)
		return (0);
	else
		return (num * sign);
}
