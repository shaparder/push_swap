/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osfally <osfally@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 23:14:57 by osfally           #+#    #+#             */
/*   Updated: 2019/05/01 19:30:25 by osfally          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_cmds	g_cmds[CMDS] =
{
	{"sa", &cmd_sa},
	{"sb", &cmd_sb},
	{"ss", &cmd_ss},
	{"pa", &cmd_pa},
	{"pb", &cmd_pb},
	{"ra", &cmd_ra},
	{"rb", &cmd_rb},
	{"rr", &cmd_rr},
	{"rra", &cmd_rra},
	{"rrb", &cmd_rrb},
	{"rrr", &cmd_rrr},
};

void			execute_cmd(t_dualstack *dual, char *line)
{
	int			i;

	i = 0;
	while (CMDS > i++)
	{
		if (ft_strcmp(line, g_cmds[i].str) == 0)
		{
			g_cmds[i].fct(dual);
			break;
		}
	}
	if (i == CMDS)
		program_end(dual, 0);
}

void			apply_cmds(t_dualstack *dual)
{
	char		*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		execute_cmd(dual, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	print_stack(A);
}
