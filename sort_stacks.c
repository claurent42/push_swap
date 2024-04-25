#include "push_swap.h"
#include <stdio.h>//to del

static void	push_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	cheapest_node = find_cheapest(*a);
	if (cheapest_node->median == 1 && (cheapest_node->target_node->median) ==1)
		rotate_both(a, b, cheapest_node);
	else if (cheapest_node->median == -1 && (cheapest_node->target_node->median) == -1)
		rev_rotate_both(a, b, cheapest_node);
	target_node_to_top(a, cheapest_node, 'a');
	target_node_to_top(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

static void	push_to_a(t_stack_node **a, t_stack_node **b)
{
	target_node_to_top(a, (*b)->target_node, 'b');
	pa(a, b);
}

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
	rr(a, b);
	set_index(*a);
	set_index(*b);
}

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while(*b != cheapest_node->target_node && *a != cheapest_node)
	rrr(a, b);
	set_index(*a);
	set_index(*b);
}

static void	target_node_to_top(t_stack_node **stack, t_stack_node *target_node, char stack_name)
{
	while (*stack != target_node)
	{
		if (stack_name == 'a')
		{
			if (target_node->median == 1)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_name == 'b')
		{
			if (target_node->median == -1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	up_min_to_top(t_stack_node **a) //maybe static fonction, why??
{	
	t_stack_node	*smallest_node;
	printf("up min IN\n");//to del
	smallest_node = find_min(*a);
	putlist(*a);//to del
	while (((*a)->value) != (smallest_node->value))
		if (smallest_node->median == 1)
			ra(a);
		else
			rra(a);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = list_lenght(*a);
//	printf("lenght :: %d\n", len_a);//to del
	if (len_a-- > 3 && stack_sorted(*a) == false)
		pb(a, b);
	if (len_a-- > 3 && stack_sorted(*a) == false)
		pb(a, b);
	while (len_a-- >3 && stack_sorted(*a) == false)
	{
		init_nodes_to_sort(*a, *b);
		printf("Check\n");//to del
		push_to_b(a, b);	
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_to_sort_from_b(*a, *b);
		push_to_a(a, b);
	}
	up_min_to_top(a);
}	
