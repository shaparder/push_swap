/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:13:02 by osfally           #+#    #+#             */
/*   Updated: 2019/05/07 10:51:57 by shaparder        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			cmd_sa(t_dualstack *dual)
{
	int			tmp;

	if (!A || A == A->next)
		return ;
	tmp = A->value;
	A->value = A->next->value;
	A->next->value = tmp;
}

void			cmd_pa(t_dualstack *dual)
{
	if (!B)
		return ;
	A = stack_push(A, B->value);
	B = stack_del(B);
}

void			cmd_ra(t_dualstack *dual)
{
	if (!A)
		return ;
	A = A->next;
}

void			cmd_rra(t_dualstack *dual)
{
	if (!A)
		return ;
	A = A->prev;
}
