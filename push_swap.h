#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

//Stack node structure
typedef struct s_stack_node
{
	int	value;
	int	index;
	int	price;
	int	median;
	bool	cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}	t_stack_node;

//Split
static int	word_counter(char *str, char spt);
static char	*word_pusher(char *str, char spt);
char	**ft_split(char *str, char spt);

//Stack init
static long	ft_atol(const char *s);
static void	add_node(t_stack_node **stack, int n);
void	init_stack(t_stack_node **stack, char **argv);
static void	target_node_to_top(t_stack_node **stack, t_stack_node *target_node, char stack_name);

//Stack utils
bool	stack_sorted(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_cheapest(t_stack_node *stack);

//Node utils
void	set_index(t_stack_node *stack);
int	set_median(t_stack_node *stack);
static void	set_target_node(t_stack_node *a, t_stack_node *b);
static void	set_price(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *stack);
void	init_nodes_to_sort(t_stack_node *a, t_stack_node *b);
void	init_nodes_to_sort_from_b(t_stack_node *a, t_stack_node *b);

//Linked list utils
unsigned int	list_lenght(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *stack);

//Algorithms
void	sort_three(t_stack_node **stack);
void	sort_stacks(t_stack_node **a, t_stack_node **b);

//Algorithms utils
static void	push_to_b(t_stack_node **a, t_stack_node **b);
static void	push_to_a(t_stack_node **a, t_stack_node **b);
static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
static void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);

//Move commands
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);

//errors
int	check_syntax(char *s);
int	check_double(t_stack_node *stack, int value);
int	check_overflow(int nbr);
void	free_error(t_stack_node **stack_a, char **argv);

//Memory
void	free_array(char **argv);
void	free_stack(t_stack_node **stack);

//Testers
void	putlist(t_stack_node *stack);
//	void	print_node(t_stack_node *node);
//	void	print_list(t_stack_node **stack);
//	int	count_moves(??);
void	sort_test(t_stack_node **stack);

#endif
