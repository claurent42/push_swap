#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>//to del

//available moves == pa :: pb

	//Init new node to store 1st A node
		//Check if source exist
		//Store 1st A node in new node
		//Move A stack pointer to 2nd node
	//Push the node to B stack
		//if B stack in empty
			//B stack point to stored node
			//Stored node pointer to next node set to NULL
		//else, if B stack is not empty
			//Stored node next point to 1st B node
			//Old 1st B node pointer to previous set to ew first node
			//B stack point to stored node
		

//void	push
static void	push(t_stack_node **src, t_stack_node **dest)
{	
	t_stack_node	*pushed_node;

	if (!*src)
		return;
	pushed_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	if (!*dest)
	{
		*dest = pushed_node;
		pushed_node->next = NULL;
	}
	else
	{
		pushed_node->next = *dest;
		pushed_node->next->previous = pushed_node;
		*dest = pushed_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
