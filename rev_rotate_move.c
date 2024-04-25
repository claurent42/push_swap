#include "push_swap.h"
#include <unistd.h>

//available moves == rra :: rrb :: rrr

//TODO verify if working
//do get_lst_node fonction

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node *last_node;


	if (*stack == NULL || !(*stack)->next)
		return;
	last_node = find_last_node(*stack);
	last_node->previous->next = NULL;
	last_node->next = *stack;
	last_node->previous = NULL;
	*stack = last_node;
	last_node->next->previous = last_node;
}

//void rra
void	rra(t_stack_node **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

//void rrb
void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

//void rrr
void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
