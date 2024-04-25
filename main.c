#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>//to del

/*TEST FONCTIONS*/
void	putlist(t_stack_node *stack)
{
	while (stack)
	{
		printf("|%d|\n", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char	**argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;

	if ((argc == 1) || (argc == 2 && !argv[1][0])) //check parenthesis
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack(&a, argv + 1);
	putlist(a);//to del
	if (stack_sorted(a) == false)
	{
		if (list_lenght(a) == 2)
			sa(&a);
		else if (list_lenght(a) == 3)
			sort_three(&a);		
		else
			sort_stacks(&a, &b);
	}
	printf("stack sorted :: %d\n", stack_sorted(a));//to del
	putlist(a);//to del
	free_stack(&a);
	return (0);
}



/********SPLIT TESTER*******		//Not Working*/
/*
int	main(int argc, char	**argv)
{
	char	**array;
	int	i;


	i = 1;
	array = split(argv[1], ' ');
	printf("split done\n");
	while (array)
	{
		if (array[i] == 0 && array[i+1] == 0)
			break;
		if (array[i] == 0)
			i++;
		printf("|%s|\n", array[i]);
		i++;
	}
	return (0);
}
*/
/********SYNTAX INPUT TESTER********/
/*
int	main(int argc, char	**argv)
{
	char	**array;
	int 	i;
	
	array = split(argv[1], ' '0);
}
*/
