#include "push_swap.h"
#include <unistd.h>

//available moves == sa :: sb :: ss

//TODO write the pseudo code

//void swap
static void	swap(t_stack_node **top)
{
	if (*top == NULL || !(*top)->next)
		return;
	*top = (*top)->next;
	(*top)->previous->previous = *top;
	(*top)->previous->next = (*top)->next;
	if ((*top)->next)
		(*top)->next->previous = (*top)-> previous;
		(*top)->next = (*top)->previous;
		(*top)->previous = NULL;
}

//void sa
void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

//void sb
void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

//void ss
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
