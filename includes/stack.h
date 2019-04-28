/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:17:37 by osfally           #+#    #+#             */
/*   Updated: 2019/04/27 17:58:35 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack				*stack_init(int value);
t_stack				*stack_push(t_stack *node, int value);
void				stack_free(t_stack *node);
int					stack_check(t_stack *head);
#endif
