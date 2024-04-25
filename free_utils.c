#include "push_swap.h"

void	free_array(char **argv) //why start at -1
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);		
}

//add free_stack from errors.c
