#include "push_swap.h"

t_stack *push_swap(char **av, int ac)
{

}
int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack || argc < 1)
	{
		write(1, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	if (is_number(av, ac))
		stack = push_swap(av, ac);
	else
	{
		write(2, "Error\n", 6);
		free(stack);
		exit(EXIT_FAILURE);
	}
	free(stack);
	//exit(EXIT_FAILURE);
	return (0);
}
