#include <unistd.h>

void	ft_print(int a)
{
	char	result;

	result = '0' + a;
	write(1, &result, 1);
}

void	ft_print_numbers(void)
{
	int	i;	

	i = 0;
	while (i <= 9)
	{
		ft_print(i);
		i++;
	}
}
