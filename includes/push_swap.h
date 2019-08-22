/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:41:48 by etuffleb          #+#    #+#             */
/*   Updated: 2019/08/22 20:32:20 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


typedef struct	s_stacks
{
	int			*a;
	int			*b;
	int			top_a;
	int			top_b;
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

//push_swap

int		is_couple(t_conv *list);
int		is_opposite(t_conv *list);
void	merge_instr(t_conv *list, int merge_case, int *optimise);


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

void	draw_status(t_stacks *sts);
void	do_instruction(t_conv *instr_arr, t_stacks *sts);
void	ft_error(char *str);
int		*create_stack(int len, char **av, int *mid);
void	is_valid(int ac, char **av);


#endif
