#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	swap;
	int	i;
	int	j;

	j = 0;
	while (j < size - 1)
	{
		i = j + 1;
		while (i < size)
		{
			if (tab[i] < tab[j])
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			i++;
		}
		j++;
	}
}
