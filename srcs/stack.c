/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:52:08 by osfally           #+#    #+#             */
/*   Updated: 2019/04/27 17:58:05 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack			*stack_init(int value)
{
	t_stack		*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->value = value;
	new->next = new;
	new->prev = new;
	return (new);
}

t_stack			*stack_push(t_stack *node, int value)
{
	t_stack		*new;

	if (node == NULL)
		return(stack_init(value));
	else if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->value = value;
	new->next = node;
	new->prev = node->prev;
	node->prev = new;
	new->prev->next = new;
	return (new);
}

void			stack_free(t_stack *node)
{
	t_stack		*end;
	t_stack		*tmp;

	if (!node)
		return ;
	end = node->prev;
	while (node != end)
	{
		tmp = node->next;
		free(node);
		node = tmp;
		tmp = NULL;
	}
	free(end);
	end = NULL;
	node = NULL;
}

int				stack_check(t_stack *head)
{
	t_stack		*tmp;
	t_stack		*end;

	tmp = head;
	end = head->prev;
	while (tmp != end)
	{
		if (tmp->next && tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
