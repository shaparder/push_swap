/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:14:47 by osfally           #+#    #+#             */
/*   Updated: 2019/04/30 13:54:59 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t			ft_ptrlen(char **ptr)
{
	size_t		len;

	len = 0;
	while(ptr[len])
		len++;
	return (len);
}

void			free_dual(t_dualstack *dual)
{
	stack_free(dual->a);
	stack_free(dual->b);
}

int				check_doublon(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack->next;
	while (tmp != stack)
	{
		if (stack->value == tmp->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			program_end(t_dualstack *dual, char *msg)
{
	free_dual(dual);
	ft_error(msg);
}
