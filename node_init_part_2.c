#include "push_swap.h"
#include <stdio.h>

void	set_target_node_from_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a_node;
	t_stack_node	*target_node;
	long		closest_bigger_value;

	while (b)
	{
		closest_bigger_value = LONG_MAX;
		current_a_node = a;
		while (current_a_node)
		{
			if (current_a_node->value > b->value
				&& current_a_node->value < closest_bigger_value)
			{
				printf("bigger value :: %d\n", current_a_node->value);//to del
				closest_bigger_value = current_a_node->value;
				target_node = current_a_node;
				printf("target node :: %d\n", target_node->value);//to del
			}
			current_a_node = current_a_node->next;
		}
	if (closest_bigger_value == LONG_MAX)
		b->target_node = find_min(a);
	else
		b->target_node = target_node;
	b = b->next;
	}
}

void	init_nodes_to_sort_from_b(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_node_from_b(a, b);
}
