#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

//available moves == ra :: rb :: rr

//TODO verify if working

//void rotate
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	if (*stack == NULL || !(*stack)->next)
		return;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last_node->next->previous = last_node;
	last_node->next->next = NULL;
}

//void ra
void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

//void rb
void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n",3);
}

//void rr
void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
