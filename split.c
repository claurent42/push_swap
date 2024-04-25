#include "push_swap.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//word_counter
static int	word_counter(char *str, char spt)
{
	int	word_c;
	bool	word_flag;

	word_c = 0;
	while (*str)
	{
		word_flag = false;
		while (*str == spt)
			str++;
		while (*str != spt && *str)
		{
			if (word_flag == false)
			{
				word_c++;
				word_flag = true;
			}
			str++;
		}
	}
	return (word_c);
}

//word_pusher
static char	*word_pusher(char *str, char spt)
{
	static int	read_head = 0;
	char		*word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[read_head] == spt)
		read_head++;
	while ((str[read_head + len] != spt) && str[read_head + len])
		len++;
	word = malloc((size_t)len * sizeof(char) + 1);
	if (!word)
		return (NULL);
	while ((str[read_head] != spt) && str[read_head])
		word[i++] = str[read_head++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char spt)
{
	int	word_c;
	char	**res_array;
	int	i;

	i = 0;
	word_c = word_counter(str, spt);
	if (!word_c)
		exit (1);
//		return ("Error")
	res_array = malloc(sizeof(char *) * (size_t)(word_c + 2));
	if (!res_array)
		return (NULL);
	while (word_c-- >= 0)
	{
		if (i == 0)
		{
			res_array[i] = malloc(sizeof(char));
			if (!res_array[i])
				return (NULL);
			res_array[i++][0] = '\0';
			continue;
		}
		res_array[i++] = word_pusher(str, spt);
	}
	res_array[i] = NULL;
	return (res_array);
}	 
