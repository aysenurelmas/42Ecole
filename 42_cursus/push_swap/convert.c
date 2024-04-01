#include "push_swap.h"

t_stack	*to_int(char **argv, int argc)
{
	t_stack	*stack;
	int		j;

	stack = NULL;
	while (--argc >= 1)
	{
		j = ft_strlen(argv[argc]);
		while (argv[argc][--j] && j >= 0)
		{
			if (argv[argc][j + 1] == '\0' && argv[argc][j] == ' ')
			{
				while (argv[argc][j] == ' ')
					j--;
			}
			while ((argv[argc][j] >= '0' && argv[argc][j] <= '9')
				|| argv[argc][j] == '-')
				j--;
			push(&stack, ft_atoi(&argv[argc][j + 1]));
			while (argv[argc][j] == ' ')
				j--;
			if (j == 0)
				push(&stack, ft_atoi(&argv[argc][j]));
		}
	}
	return (stack);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		n;
	int		num;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	n = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	num = 0;
	while (str[i] != 0 && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * n);
}
