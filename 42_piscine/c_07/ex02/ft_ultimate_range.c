#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	j;
	int	i;
	int	size;

	size = max - min;
	j = min;
	i = 1;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (size));
	if (!(range))
		return (-1);
	(*range)[0] = j;
	j++;
	while (i < size)
	{
		(*range)[i] = j;
		j++;
		i++;
	}
	return (i);
}
