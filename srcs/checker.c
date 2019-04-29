/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:33:23 by osfally           #+#    #+#             */
/*   Updated: 2019/04/28 16:42:21 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t			ft_ptrlen(char **ptr)
{
	size_t		len;

	len = 0;
	while(ptr[len])
		len++;
	return (len);
}

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

	if (!(dual = malloc(sizeof(t_dualstack))))
		return (0);
	a = NULL;
	b = NULL;
	A = a;
	B = b;
	(argc == 1) ? stack_error(dual, "Error.") : 0;
	argv = (argc == 2) ? ft_strsplit(argv[1], 32) : argv++;
	i = (argc == 2) ? ft_ptrlen(argv) : argc - 1;
	while (i--)
		a = stack_push(a, ft_atoi(argv[i]));
	if (stack_check(a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_dual(dual);
	return (1);
}
