/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:52:23 by shaparder         #+#    #+#             */
/*   Updated: 2019/05/09 16:49:54 by shaparder        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void			split_to_b(t_dualstack *dual, int median, int size)
{
	int			swp;
	int			rtt;

	swp = 0;
	rtt = 0;
	while (swp < (size/2))
	{
		if (A->value <= median)
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
}

int				find_median_value(t_stack *stack)
{
	int			sum;
	int			size;
	t_stack		*tmp;

	tmp = stack->next;
	sum = stack->value;
	size = 1;
	while (tmp != stack)
	{
		sum += tmp->value;
		size += 1;
		tmp = tmp->next;
	}
	return (sum / size);
}

void			backtrack_merge(t_dualstack *dual, int split_size)
{
	if (stack_sorted(A))
		return ;
	split_to_b(dual, find_median_value(A), split_size);
	backtrack_merge(dual, (split_size/2));
	push_to_a(dual, split_size);
	if (split_size < 6)
		quick_sort(A, split_size);
	else
		backtrack_merge(dual, split_size);
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
		quick_sort(A, stack_size(A));
	else
		backtrack_merge(dual, stack_size(A));
	program_end(dual, 1);
	// system("leaks checker");
	return (EXIT_SUCCESS);
}
