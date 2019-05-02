/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:13:02 by osfally           #+#    #+#             */
/*   Updated: 2019/05/01 20:27:30 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			cmd_sa(t_dualstack *dual)
{
	int			tmp;


	if (!A && A == A->next)
		return ;
	tmp = A->value;
	A->value = A->next->value;
	A->next->value = tmp;
}

void			cmd_pa(t_dualstack *dual)
{
	if (!B)
		return ;


}
