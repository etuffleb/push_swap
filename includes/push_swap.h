/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:41:48 by etuffleb          #+#    #+#             */
/*   Updated: 2019/09/18 21:37:28 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stacks
{
	int			*a;
	int			*b;
	int			top_a;
	int			top_b;
	int rest;
}				t_stacks;

typedef struct		s_conv
{
	char			*instr;
	void			(*f)(t_stacks *);
	struct s_conv	*next;
}					t_conv;

typedef struct		s_norm
{
	t_conv			*list;
	t_stacks		*stas;
}					t_norm;

int		check_stacks(t_stacks *sts);
void	fill_instr(char *instruction, t_conv *instr_arr);
void	read_line(t_stacks *sts);
char	*run_checker(int *a, int *b, int top);

int		is_couple(t_conv *list);
int		is_opposite(t_conv *list);
void	merge_instr(t_conv *list, int merge_case, int *optimise);

void	rb(t_stacks *sts);
void	ra(t_stacks *sts);
void	rr(t_stacks *sts);
void	sb(t_stacks *sts);
void	sa(t_stacks *sts);
void	ss(t_stacks *sts);
void	pa(t_stacks *sts);
void	pb(t_stacks *sts);
void	rra(t_stacks *sts);
void	rrb(t_stacks *sts);
void	rrr(t_stacks *sts);

void	draw_status(int *a, int *b);
void	do_instruction(t_conv *instr_arr, t_stacks *sts);
void	ft_error(char *str);
int		*create_stack(int len, char **av);
void	sort_stack_b(t_conv *list, t_stacks *sts, int max_i);
void	quick_sort_a(t_conv *list, t_stacks *sts, int max_i, int is_first);
void	optimise_instructions(t_conv *instr_list);
double	ft_pivot(int *stack, int top, int size);
void	add_to_list(t_stacks *sts, t_conv *list, char *str);
void	insertion_sort(t_conv *list, t_stacks *sts, int top, int *sample);
int		*is_valid(int ac, char **av);

#endif
