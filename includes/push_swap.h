/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:41:48 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/05 19:04:55 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

# define RESET	"\033[0m"
# define GREEN	"\033[1;32m"

typedef struct	s_stacks
{
	int			*a;
	int			*b;
	int			top_a;
	int			top_b;
	int			min;
	int			mid;
	int			max;
}				t_stacks;

typedef struct		s_conv
{
	char			*instr;
	void			(*f)(t_stacks *);
	struct s_conv	*next;
}					t_conv;

//checker

int		check_stacks(t_stacks *sts);
void	fill_instr(char *instruction, t_conv *instr_arr);
void	read_line(t_stacks *sts);
char	*run_checker(int *a, int *b, int top);
void	draw_status(t_stacks *sts, int hight);
// opt

int		is_couple(t_conv *list);
int		is_opposite(t_conv *list);
void	merge_instr(t_conv *list, int merge_case, int *optimise);
void	optimise_instructions(t_conv *instr_list);

//op

void rb(t_stacks *sts);
void ra(t_stacks *sts);
void rr(t_stacks *sts);
void sb(t_stacks *sts);
void sa(t_stacks *sts);
void ss(t_stacks *sts);
void pa(t_stacks *sts);
void pb(t_stacks *sts);
void rra(t_stacks *sts);
void rrb(t_stacks *sts);
void rrr(t_stacks *sts);

//tools

void	draw_test(int *a, int *b);
void	do_instruction(t_conv *instr_arr, t_stacks *sts);
void	ft_error(char *str);
void	add_to_list(t_stacks *sts, t_conv *list, char *str);
int		ft_min_a(int *a, int top);
int		ft_max_a(int *a, int top);
void	start_vizualisation(t_stacks *sts, t_conv *instr_list);

//init val

int		*create_stack(int ac, char **av, int *top);
int 	*is_valid(int ac, char **av, int *top);
int		*is_valid_str(char **av, int *top);

// qs

void	sort_stack_b(t_conv *list, t_stacks *sts, int max_i);
void	sort_stack_a(t_conv *list, t_stacks *sts, int max_i, int is_first);
double	ft_pivot(int *stack, int top, int size);

void	insertion_sort(t_conv *list, t_stacks *sts, int top, int *sample);

void	boring_sort(t_conv *list, t_stacks *sts, int top);
void	smart_sort(t_conv *list, t_stacks *sts, int top);
void	sort_a_in_needed_order(t_conv *list, t_stacks *sts, int top);
int		find_min_i(t_stacks *sts);
void	add_list_of_instr(t_conv *list, t_stacks *sts, int i);
void	rotate_until(t_conv *list, t_stacks *sts);

#endif
