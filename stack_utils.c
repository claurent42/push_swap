#include "push_swap.h"
#include <stdio.h>//to del

bool	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack=stack->next;
	}
	return (true);
}

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*first_node;
	int	first_value;

	first_node = *stack;
	first_value = first_node -> value;
	if (((first_value) > (first_node->next->value))
		&& ((first_value) > (first_node->next->next->value)))
		{	
		ra(stack);
		if (stack_sorted(*stack) == false)
			sa(stack);
		}	
	else if ((first_node->next->value) > (first_value))
		{
		rra(stack);
		if (stack_sorted(*stack) == false)
			sa(stack);
		}
	else
		sa(stack);
}
