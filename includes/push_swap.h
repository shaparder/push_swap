/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:38:32 by osfally           #+#    #+#             */
/*   Updated: 2019/04/30 19:33:41 by osfally          ###   ########.fr       */
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

# define A			(dual->a)
# define B			(dual->b)

// helpers
size_t				ft_ptrlen(char **ptr);
void				ft_ptrfree(char **ptr);
void				free_dual(t_dualstack *dual);
int					verify_arg(char *arg, t_stack *stack);
void				program_end(t_dualstack *dual, char *msg);
// stack
t_stack				*stack_init(int value);
t_stack				*stack_push(t_stack *node, int value);
void				stack_free(t_stack *node);
int					stack_sorted(t_stack *head);
void				print_stack(t_stack *stack);

#endif
