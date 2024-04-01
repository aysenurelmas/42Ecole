#include "push_swap.h"

int	is_number(char **argv, int argc)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j - 1] == ' ' || argv[i][j - 1] == '\t')
				k = 0;
			while ((argv[i][j] == '-' || argv[i][j] == '+') && ++j)
				k++;
			if (((argv[i][j] != '-') && (argv[i][j] < '0' || argv[i][j] > '9')
						&& (argv[i][j] != 32 && argv[i][j] != '\t')) || k > 1)
				return (0);
			j++;
		}
		i++;
		k = 0;
	}
	return (1);
}
