#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

void	set_index(t_stack_node *stack)
{
	int	i;
	int	median_position;

	i = 0;
	if (stack == NULL)
		return;
	median_position = set_median(stack);
	while (stack)
	{
		stack->index = i;
		if (i <= median_position)
			stack->median = 1;
		else
			stack->median = -1;
		stack = stack->next;
		i++;
	}
}

int	set_median(t_stack_node *stack)
{
	int	res;
	
	res = list_lenght(stack) / 2;
	return (res);
}

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long		best_match_index; //stores "closest smaller number" value so far

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
	if (best_match_index == LONG_MIN)
		a->target_node = find_max(b);
	else
		a->target_node = target_node;
	a = a->next;
	}
}

static void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = list_lenght(a);
	len_b = list_lenght(b);
	while (a)
	{
	a->price = a->index;
	if (a->median = -1)
		a->price = len_a - (a->index);
	if (a->target_node->median = 1)
		a->price = a->price + a->target_node->index;
	else
		a->price += len_b - (a->target_node->index); 
	a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long	cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->price < cheapest_value)
		{
			cheapest_value = stack->price;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_to_sort(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(a);
}
