/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:52:08 by osfally           #+#    #+#             */
/*   Updated: 2019/05/07 11:43:58 by shaparder        ###   ########.fr       */
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

t_stack			*stack_push(t_stack *stack, int value)
{
	t_stack		*new;

	if (stack == NULL)
		return (stack_init(value));
	else if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->value = value;
	new->next = stack;
	new->prev = stack->prev;
	stack->prev = new;
	new->prev->next = new;
	return (new);
}

t_stack			*stack_del(t_stack *stack)
{
	t_stack		*tmp;

	if (stack == stack->next)
	{
		free(stack);
		stack = NULL;
		return (stack);
	}
	tmp = stack->next;
	stack->next->prev = stack->prev;
	stack->prev->next = stack->next;
	free(stack);
	stack = NULL;
	return (tmp);
}

void			stack_free(t_stack *stack)
{
	t_stack		*end;
	t_stack		*tmp;

	if (!stack)
		return ;
	end = stack->prev;
	while (stack != end)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
		tmp = NULL;
	}
	free(end);
}

int				stack_sorted(t_stack *head)
{
	t_stack		*tmp;
	t_stack		*end;

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

// to delete after
void			print_stack(t_stack *stack)
{
	t_stack		*end;
	t_stack		*tmp;

	end = stack->prev;
	tmp = stack;
	while (tmp != end)
	{
		ft_putnbr(tmp->value);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putnbr(tmp->value);
	ft_putchar('\n');
}
