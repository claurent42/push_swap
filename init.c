#include "push_swap.h"
#include <stdbool.h>
#include <stdio.h>


static long	ft_atol(const char *s)
{
	long	res;
	int	sign;

	res = 0;
	sign = 1;
	while(*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' 
		|| *s == '\f' || *s == '\v')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = (res *10 + (*s - '0'));
		*s++;
	}
	return (res * sign);
}

static void	add_node(t_stack_node **stack, int i)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return;
	new_node->value = i;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->previous = NULL;
	}
	else
	{	
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->previous = last_node;
	}
}

void	init_stack(t_stack_node **stack_a, char **argv)
{
	long	nbr;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (check_syntax(argv[i]) == 1)
			free_error(stack_a, argv);
		nbr = ft_atol(argv[i]);
		if (check_overflow(nbr) == 1)
			free_error(stack_a, argv);
		if (check_double(*stack_a, (int)nbr))
			free_error(stack_a, argv);
		add_node(stack_a, (int)nbr);
		++i;
	}
//Maybe have to free array made by split
}

/*bool	stack_sorted(t_stack_node *stack)
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
*/
