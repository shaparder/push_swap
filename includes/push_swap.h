/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:38:32 by osfally           #+#    #+#             */
/*   Updated: 2019/04/27 18:35:16 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "stack.h"

typedef struct		s_dualstack
{
	t_stack			*a;
	t_stack			*b;
}					t_dualstack;

# define A			(dual->a)
# define B			(dual->b)

#endif
