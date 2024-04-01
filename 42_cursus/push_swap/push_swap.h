#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int				content;
	int				index;
	struct stack	*next;
}a_stack, b_stack, t_stack;
#endif
