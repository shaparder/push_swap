/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:47:52 by shaparder         #+#    #+#             */
/*   Updated: 2019/05/06 14:56:22 by shaparder        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			cmd_sb(t_dualstack *dual)
{
	int			tmp;


	if (!B || B == B->next)
		return ;
	tmp = B->value;
	B->value = B->next->value;
	B->next->value = tmp;
}

void			cmd_pb(t_dualstack *dual)
{
	if (!A)
		return ;
	B = stack_push(B, A->value);
	A = stack_del(A);
}

void			cmd_rb(t_dualstack *dual)
{
	if (!B)
		return ;
	B = B->next;
}

void			cmd_rrb(t_dualstack *dual)
{
	if (!B)
		return ;
	B = B->prev;
}
