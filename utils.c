#include "push_swap.h"
#include <stdio.h>//to del

unsigned int	list_lenght(t_stack_node *stack)
{
	int	c;

	if (!stack)
		return (0);
	c = 0;
	while (stack)
	{
		stack = stack->next;
		c++;
	}
	return (c);
}

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long	max_value;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max_value = INT_MIN;
	while (stack)
	{
		if (stack->value > max_value)
		{
			stack->value = max_value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return(max_node);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long	min_value;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min_value = INT_MAX;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return(min_node);
}


t_stack_node	*find_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
