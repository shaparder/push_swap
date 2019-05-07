/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:56:40 by shaparder         #+#    #+#             */
/*   Updated: 2019/05/06 15:01:00 by shaparder        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			cmd_ss(t_dualstack *dual)
{
	cmd_sa(dual);
	cmd_sb(dual);
}

void			cmd_rr(t_dualstack *dual)
{
	cmd_ra(dual);
	cmd_rb(dual);
}

void			cmd_rrr(t_dualstack *dual)
{
	cmd_rra(dual);
	cmd_rrb(dual);
}
