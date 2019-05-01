/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:14:47 by osfally           #+#    #+#             */
/*   Updated: 2019/04/30 19:33:41 by osfally          ###   ########.fr       */
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

void			ft_ptrfree(char **ptr)
{
	int 		i;

	i = 0;
	if(!ptr)
		return ;
	while (ptr[i])
		ft_strdel(&ptr[i]);
	free(ptr);
}

void			free_dual(t_dualstack *dual)
{
	stack_free(dual->a);
	stack_free(dual->b);
}

void			program_end(t_dualstack *dual, char *msg)
{
	free_dual(dual);
	ft_error(msg);
}

int				verify_arg(char *str, t_stack *stack)
{
	t_stack		*tmp;
	intmax_t	nbr;

	if (!ft_strisnbr(str) || (nbr = ft_atoimax(str)) > INT_MAX || nbr < INT_MIN)
		return (0);
	else if (stack && stack->value == (int)nbr)
		return (0);
	else if (stack)
	{
		tmp = stack->next;
		while (tmp != stack)
		{
			if (tmp->value == (int)nbr)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}
