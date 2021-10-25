#include <unistd.h>

void	ft_print(int a)
{
	char	result;

	result = '0' + a;
	write(1, &result, 1);
}

void	ft_print_comb(void)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	while (x <= 7)
	{
		y = x + 1;
		while (y <= 8)
		{
			z = y + 1;
			while (z <= 9)
			{
				ft_print(x);
				ft_print(y);
				ft_print(z);
				if (x != 7 || y != 8 || z != 9)
					write(1, ", ", 2);
				z++;
			}
			y++;
		}
		x++;
	}	
}
