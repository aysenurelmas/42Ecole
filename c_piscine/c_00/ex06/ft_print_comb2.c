#include <unistd.h>

void	ft_print(int a)
{
	char	result;

	result = '0' + a;
	write(1, &result, 1);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			ft_print(x / 10);
			ft_print(x % 10);
			write(1, " ", 1);
			ft_print(y / 10);
			ft_print(y % 10);
			if (x != 98 || y != 99)
				write(1, ", ", 2);
			y++;
		}
		x++;
	}	
}
