#include "push_swap.h"

//Handel syntax/input error
//Handel repetition error
//Free stacks

int	check_syntax(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (*++s)
		if (!(*s >= '0' && *s <= '9'))
			return (1);
	return (0);
}

int	check_double(t_stack_node *node, int value)
{
	if (node == NULL)
		return (0);
	while (node)
	{
		if (node->value == value)
			return (1);
		node = node->next;
	}
	return (0);
}

int	check_overflow(int nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (1);
	return (0);
}

void	free_error(t_stack_node **stack_a, char **argv)
{
	free_stack(stack_a);
	//free split array
	exit (1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (stack == NULL)
		return;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
