/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:38:32 by osfally           #+#    #+#             */
/*   Updated: 2019/05/07 08:06:27 by shaparder        ###   ########.fr       */
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

typedef struct		s_cmds
{
	char			*str;
	void			(*fct)(t_dualstack *dual);
}					t_cmds;

# define CMDS		11
# define A			(dual->a)
# define B			(dual->b)

extern t_cmds		g_cmds[CMDS];
// helpers
size_t				ft_ptrlen(char **ptr);
void				ft_ptrfree(char **ptr);
void				free_dual(t_dualstack *dual);
int					verify_arg(char *arg, t_stack *stack);
void				program_end(t_dualstack *dual, int status);
// stack
t_stack				*stack_init(int value);
t_stack				*stack_push(t_stack *node, int value);
t_stack				*stack_del(t_stack *stack);
void				stack_free(t_stack *node);
int					stack_sorted(t_stack *head);
void				print_stack(t_stack *stack);
// cmd exec
void				apply_cmds(t_dualstack *dual);
void				execute_cmd(t_dualstack *dual, char *line);
// cmd list
void				cmd_sa(t_dualstack *dual);
void				cmd_sb(t_dualstack *dual);
void				cmd_ss(t_dualstack *dual);
void				cmd_pa(t_dualstack *dual);
void				cmd_pb(t_dualstack *dual);
void				cmd_ra(t_dualstack *dual);
void				cmd_rb(t_dualstack *dual);
void				cmd_rr(t_dualstack *dual);
void				cmd_rra(t_dualstack *dual);
void				cmd_rrb(t_dualstack *dual);
void				cmd_rrr(t_dualstack *dual);

#endif
