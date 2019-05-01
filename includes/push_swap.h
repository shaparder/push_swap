/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:38:32 by osfally           #+#    #+#             */
/*   Updated: 2019/04/30 23:59:58 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>

//structs
typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_dualstack
{
	t_stack			*a;
	t_stack			*b;
}					t_dualstack;

typedef struct		s_pswap
{
	char			*str;
	void			(*fct)(t_dualstack *dual);
}					t_pswap;

# define INST		11
# define A			(dual->a)
# define B			(dual->b)

extern t_pswap		g_pswap[INST];
// helpers
size_t				ft_ptrlen(char **ptr);
void				ft_ptrfree(char **ptr);
void				free_dual(t_dualstack *dual);
int					verify_arg(char *arg, t_stack *stack);
void				program_end(t_dualstack *dual, int status);
// stack
t_stack				*stack_init(int value);
t_stack				*stack_push(t_stack *node, int value);
void				stack_free(t_stack *node);
int					stack_sorted(t_stack *head);
void				print_stack(t_stack *stack);
// instructions
void				apply_instructions(t_dualstack *dual);
void				execute_inst(t_dualstack *dual, char *line);

#endif
