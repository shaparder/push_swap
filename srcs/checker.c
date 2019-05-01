/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:33:23 by osfally           #+#    #+#             */
/*   Updated: 2019/04/30 19:35:00 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			apply_instruction(t_dualstack *dual, char *line)
{
	B = NULL;
	ft_strdel(&line);
}

int				main(int argc, char **argv)
{
	int			i;
	t_dualstack	*dual;
	t_stack		*a;
	t_stack		*b;
	char		*line;

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
		if (!verify_arg(argv[i], a))
			program_end(dual, "Error.");
		a = stack_push(a, ft_atoi(argv[i]));
	}
	while (get_next_line(0, &line))
		apply_instruction(dual, line);
	print_stack(a);
	(stack_sorted(a)) ? ft_putendl("OK") : ft_putendl("KO");
	free_dual(dual);
	(argc == 2) ? ft_ptrfree(argv) : 0;
	return (EXIT_SUCCESS);
}
