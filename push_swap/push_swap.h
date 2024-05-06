/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:25:38 by alvaquer          #+#    #+#             */
/*   Updated: 2024/03/11 13:12:28 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				coste_total;
	struct s_list	*next;
}	t_list;

void	new_nodo(int content, int pos, t_list **lst);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *cadena);

void	*ft_memcpy(void *dest, const void *origen, size_t num);

char	*ft_strdup(const char *s1);

char	**ft_split(char const *s, char c);

void	frees(char **res);

void	free_list(t_list **a);

long	ft_numero(const char *str);

char	**read_all(int nargs, char **vargs);

char	*read_args(int nargs, char **vargs);

t_list	*create_list(char **res);

int		is_valid(int numero, t_list *lst);

int		is_a_number(char *str);

void	order_index(t_list *lst);

void	sort_brain(t_list **lst, int i);

void	sort_two(t_list **lst);

void	sort_three(t_list **lst);

void	sort_more(t_list **lst);

void	pa(t_list **a, t_list **b, int both);

void	pb(t_list **b, t_list **a, int both);

void	sa(t_list **a, int both);

void	sb(t_list **b, int both);

void	ss(t_list **a, t_list **b, int both);

void	ra(t_list **lst, int both);

void	rb(t_list **lst, int both);

void	rr(t_list **a, t_list **b, int both);

void	rra(t_list **lst, int both);

void	rrb(t_list **lst, int both);

void	rrr(t_list **a, t_list **b, int both);

void	move_to_b(t_list **a, t_list **b);

void	show_stacks(t_list **a, t_list **b);

void	fix_position(t_list **a, t_list **b);

int		lastpos(t_list **a);

void	target_position(t_list **a, t_list **b);

void	target_pos_max(t_list **a, t_list *d);

int		target_pos_min(t_list *c, t_list *d);

void	print_stack(t_list *stack);

void	cost(t_list **a, t_list **b);

int		find_cheaper(t_list **b);

void	move_cheaper(t_list **a, t_list **b, int pos);

int		positive(int num);

void	update_costs_and_positions(t_list **a, t_list **b);

void	check_order(t_list **a);

void	fix_position_a(t_list **c, int i);

void	fix_position_b(t_list **d, int i);

void	move_while_both_neg(t_list **a, t_list **b, int *i, int *j);

void	move_while_both_pos(t_list **a, t_list **b, int *i, int *j);

void	move_while_i_neg_j_pos(t_list **a, t_list **b, int *i, int *j);

void	move_while_i_pos_j_neg(t_list **a, t_list **b, int *i, int *j);

void	move_while_i_neg_j_zero(t_list **a, int *i);

void	move_while_i_pos_j_zero(t_list **a, int *i);

void	move_while_i_zero_j_neg(t_list **b, int *j);

void	move_while_i_zero_j_pos(t_list **b, int *j);

void	check_rotate(t_list **a, int pos);

int		sub_media(t_list **a, int media);

int		media(t_list *a);

int		get_min(t_list *a);

int		total_cost(int cost_a, int cost_b);

int		is_sorted(t_list **a);

bool	ft_strcmp(char *str_1, char *str_2);

void	execute_line(char *line, t_list **a, t_list **b);

void	find_error(t_list *a, t_list *b);

void	b_not_null(char *line, t_list **a, t_list **b);

void	message_final(t_list **a, t_list **b);

t_list	*delete(t_list **lst);

#endif