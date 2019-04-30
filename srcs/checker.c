/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:33:23 by osfally           #+#    #+#             */
/*   Updated: 2019/04/30 13:57:24 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				main(int argc, char **argv)
{
	int			i;
	t_dualstack	*dual;
	t_stack		*a;
	t_stack		*b;

	if (!(dual = malloc(sizeof(t_dualstack))))
		return (EXIT_FAILURE);
	a = NULL;
	b = NULL;
	A = a;
	B = b;
	(argc == 1) ? program_end(dual, "Error.") : 0;
	argv = (argc == 2) ? ft_strsplit(argv[1], 32) : &argv[1];
	i = (argc == 2) ? ft_ptrlen(argv) : argc - 1;
	while (i--)
	{
		a = stack_push(a, ft_atoi(argv[i]));
		if (check_doublon(a))
			program_end(dual, "Error.");
	}
	print_stack(a);
	// apply_instructions(dual);
	if (stack_sorted(a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_dual(dual);
	// system("leaks checker");
	return (EXIT_SUCCESS);
}
