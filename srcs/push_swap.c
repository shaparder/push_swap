/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:52:23 by shaparder         #+#    #+#             */
/*   Updated: 2019/05/13 14:36:52 by shaparder        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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

// int				find_median_value(t_stack *stack)
// {
// 	int			sum;
// 	int			size;
// 	t_stack		*tmp;

// 	tmp = stack->next;
// 	sum = stack->value;
// 	size = 1;
// 	while (tmp != stack)
// 	{
// 		sum += tmp->value;
// 		size += 1;
// 		tmp = tmp->next;
// 	}
// 	return (sum / size);
// }

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

void			backtrack_merge(t_dualstack *dual, int size)
{
	int			swp;
	int			bck;

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

int				main(int argc, char **argv)
{
	int			i;
	t_dualstack	*dual;

	if (!(dual = malloc(sizeof(t_dualstack))))
		return (EXIT_FAILURE);
	A = NULL;
	B = NULL;
	(argc == 1) ? program_end(dual, 0) : 0;
	argv = (argc == 2) ? ft_strsplit(argv[1], ' ') : &argv[1];
	i = (argc == 2) ? ft_ptrlen(argv) : argc - 1;
	while (i--)
	{
		if (!verify_arg(argv[i], A))
			program_end(dual, 0);
		A = stack_push(A, ft_atoi(argv[i]));
	}

	if (stack_size(A) < 6)
		bubble_sort(dual, stack_size(A));
	else
		backtrack_merge(dual, stack_size(A));
	program_end(dual, 1);
	// system("leaks checker");
	return (EXIT_SUCCESS);
}
