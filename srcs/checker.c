/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaparder <shaparder@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:33:23 by osfally           #+#    #+#             */
/*   Updated: 2019/05/08 14:39:39 by shaparder        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	apply_cmds(dual);
	program_end(dual, 1);
	// system("leaks checker");
	return (EXIT_SUCCESS);
}
