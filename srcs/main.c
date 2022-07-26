/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/07/22 19:11:21 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*g_env = NULL;
static void	pars_and_pipe(char *line);
static void	the_loop(void);

int	main(int argc, char **argv, char **env)
{
	char *evil[3] = { "export", "SHELL=evil_shell", (char *)0 };

	(void)argv;
	(void)argc;
	catch_signals();
	turn_env_into_list(env);
	set_ret_value(0);
	export(evil);
	the_loop();
	ft_exit_builtin(NULL);
	ft_putendl_fd("Or maybe you can, well done i give you your shell back, however try change it back a better one ;)", 1);
	return (0);
}

static void	the_loop(void)
{
	char		*line;

	while (42)
	{
		catch_signals();
		line = prompt();
		if (line)
		{
			if (ft_strcmp(line, "\\033") == 0)
			{
				free(line);
				break;
			}
			if (line[0] != '\0')
				pars_and_pipe(line);
			else
				free(line);
		}
		ft_putstr_fd("\n\033[1mREMEMBER TO LOCK YOUR SESSION, AND GET RID OF ME !!!\033[m\n\n", 2);
	}
}

static void	pars_and_pipe(char *line)
{
	t_parstab	tab;
	char		**env;

	add_history(line);
	tab = full_parsing(line);
	if (tab)
	{
		env = turn_env_into_tab();
		pipex(tab, env);
		free_parstab(tab);
		free_tabtab(env);
	}
	else
		set_ret_value(2);
}
