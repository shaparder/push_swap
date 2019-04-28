/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:33:23 by osfally           #+#    #+#             */
/*   Updated: 2019/04/27 18:37:20 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			free_dual(t_dualstack *dual)
{
	stack_free(dual->a);
	stack_free(dual->b);
}

void			stack_error(t_dualstack *dual, char *msg)
{
	free_dual(dual);
	ft_error(msg);
}

int				main(int argc, char **argv)
{
	int			i;
	t_dualstack	*dual;
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		stack_error(dual, "Error.");

	a = NULL;
	i = 1;
	while (i < argc)
		a = stack_push(a, ft_atoi(argv[i]));


	if (stack_check(a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (1);
}
