#include <stdlib.h>
#include<stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	j;
	int	i;

	j = min;
	i = 0;
	if (min >= max)
		return (0);
	tab = malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (0);
	while (i < max - min)
	{
		tab[i] = j;
		i++;
		j++;
	}
	return (tab);
}
