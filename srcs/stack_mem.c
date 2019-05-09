/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:52:08 by osfally           #+#    #+#             */
/*   Updated: 2019/05/09 16:45:32 by shaparder        ###   ########.fr       */
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
	t_stack		*end_a;
	t_stack		*end_b;
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	if (A)
	{
		tmp_a = A;
		end_a = A->prev;
	}
	else
		tmp_a = NULL;
	if (B)
	{
		tmp_b = B;
		end_b = B->prev;
	}
	else
		tmp_b = NULL;
	printf("   Stack A     Stack B    \n");
	ft_putendl("  |--------|  |--------|  ");
	while ((tmp_a && tmp_a != end_a) || (tmp_b && tmp_b != end_b))
	{
		printf("  |");
		if (tmp_a && tmp_a != end_a)
		{
			printf("%-8i", tmp_a->value);
			tmp_a = tmp_a->next;
		}
		else
			printf("        ");
		printf("|  |");
		if (tmp_b && tmp_b != end_b)
		{
			printf("%-8i", tmp_b->value);
			tmp_b = tmp_b->next;
		}
		else
			printf("        ");
		printf("|  \n");
	}
	printf("  |");
	if (tmp_a)
		printf("%-8i", tmp_a->value);
	else
		printf("        ");
	printf("|  |");
	if (tmp_b)
		printf("%-8i", tmp_b->value);
	else
		printf("        ");
	printf("|  \n");
	ft_putendl("  |--------|  |--------|  ");
}
