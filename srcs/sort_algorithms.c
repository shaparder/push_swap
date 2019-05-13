/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:59:16 by shaparder         #+#    #+#             */
/*   Updated: 2019/05/13 18:29:49 by shaparder        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				*lowest_tab(t_stack *stack, int size)
{
	int			min;
	int			i;
	int			j;
	int			*tab;
	t_stack		*tmp;

	if (!(tab = (int*)malloc(sizeof(int) * size/2)))
		return (NULL);
	i = 0;
	tmp = stack;
	while (i < size/2)
	{
		j = -1;
		min = INT_MAX;
		while (++j < size)
		{
			if (tmp->value < min && !(ft_intintab(tmp->value, tab, i)))
				min = tmp->value;
			tmp = tmp->next;
		}
		tmp = stack;
		tab[i] = min;
		i++;
	}
	return (tab);
}

void			bubble_sort(t_dualstack *dual, int size)
{
	int			b1;
	int			b2;
	int			rtt;

	rtt = 0;
	b1 = size - 1;
	while (b1 && !(stack_sorted(A, size)))
	{
		b2 = b1;
		while (b2)
		{
			if (A->value > A->next->value)
			{
				execute_cmd(dual, "sa", 1);
				if (b2 > 1)
					execute_cmd(dual, "ra", 1);
			}
			else
				execute_cmd(dual, "ra", 1);
			b2--;
		}
		while (++b2 != b1)
			execute_cmd(dual, "rra", 1);
		b1--;
	}
}

int				pushback_to_a(t_dualstack *dual, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		execute_cmd(dual, "pa", 1);
		i++;
	}
	return (i);
}

int				split_to_b(t_dualstack *dual, int *lowest_tab, int size)
{
	int			swp;
	int			rtt;

	swp = 0;
	rtt = 0;
	while (swp < (size/2))
	{
		if (ft_intintab(A->value, lowest_tab, size/2))
		{
				execute_cmd(dual, "pb", 1);
				swp++;
		}
		else
		{
				execute_cmd(dual, "ra", 1);
				rtt++;
		}
	}
	while (rtt)
	{
		execute_cmd(dual, "rra", 1);
		rtt--;
	}
	free(lowest_tab);
	return (swp);
}


void			backtrack_merge(t_dualstack *dual, int size)
{
	int			swp;
	int			bck;

	print_dual(dual);
	if (stack_sorted(A, stack_size(A)))
		return ;
	swp = split_to_b(dual, lowest_tab(A, size), size);
	backtrack_merge(dual, (size - swp));
	bck = pushback_to_a(dual, swp);
	if (bck < 6)
		bubble_sort(dual, bck);
	else
		backtrack_merge(dual, bck);
}
