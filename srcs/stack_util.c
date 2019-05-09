/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:28:16 by shaparder         #+#    #+#             */
/*   Updated: 2019/05/09 15:49:48 by shaparder        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				stack_sorted(t_stack *head)
{
	t_stack		*tmp;
	t_stack		*end;

	if (!head)
		return (1);
	tmp = head;
	end = head->prev;
	while (tmp != end)
	{
		if (tmp->next && tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int				stack_size(t_stack *stack)
{
	int			size;
	t_stack		*tmp;
	t_stack		*end;

	size = 0;
	if (!stack)
		return (size);
	else
		size = 1;
	tmp = stack;
	end = stack->prev;
	while (tmp != end);
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
