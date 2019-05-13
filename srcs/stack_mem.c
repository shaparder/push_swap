/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:52:08 by osfally           #+#    #+#             */
/*   Updated: 2019/05/13 18:46:34 by shaparder        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// delete this include when pushing project
#include <stdio.h>

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

// to delete after
void			print_dual(t_dualstack *dual)
{
	int			a_size = stack_size(A);
	int			b_size = stack_size(B);
	t_stack		*tmp_a = (A) ? A : NULL;
	t_stack		*tmp_b = (B) ? B : NULL;

	printf("   Stack A     Stack B    \n");
	ft_putendl("  |--------|  |--------|  ");
	while (a_size || b_size)
	{
		printf("  |");
		if (a_size && tmp_a)
		{
			printf("%-8i", tmp_a->value);
			tmp_a = tmp_a->next;
			a_size--;
		}
		else
			printf("        ");
		printf("|  |");
		if (b_size && tmp_b)
		{
			printf("%-8i", tmp_b->value);
			tmp_b = tmp_b->next;
			b_size--;
		}
		else
			printf("        ");
		printf("|  \n");
	}
	ft_putendl("  |--------|  |--------|  ");
}
