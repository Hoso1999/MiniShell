/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:47:15 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/29 21:52:41 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	s_quit(int signum)
{
	(void)signum;
	if (g_signal.pid > 0 && !g_signal.heredoc)
	{
		printf("Quit (core dumped)\n");
		kill(g_signal.pid, SIGINT);
		g_signal.exit_status = 131;
	}
}

void	s_int(int signum)
{
	char	*copy;

	copy = ft_strdup(rl_line_buffer);
	(void)signum;
	if (g_signal.heredoc && g_signal.pid == 0)
	{
		printf("\b\b^C\b\b");
		g_signal.exit_status = 1;
		exit(g_signal.exit_status);
	}
	if (g_signal.pid == -1)
		ft_signals_print(copy);
	else
	{
		printf("\b\n");
		rl_replace_line("", 0);
		if (g_signal.pid == -1)
			rl_on_new_line();
		rl_redisplay();
		g_signal.exit_status = 130;
	}
	ft_strdel(&copy);
}

int	ft_process_signal(t_dict *lcmd)
{
	(void)lcmd;
	g_signal.pid = -1;
	signal(SIGINT, s_int);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}

int	ft_print_error(int errnum, t_pipe *pips, char **str)
{
	int	id;
	int	pip_ret;

	(void)errnum;
	pip_ret = pipe(pips->fd);
	id = fork();
	if (id < 0 || pip_ret < 0)
	{
		ft_putendl_fd(strerror(errno), 2);
		g_signal.exit_status = errno;
		ft_vecstrdel(&str);
		return (-1);
	}
	return (id);
}

int	ft_iszero(int end, int count)
{
	if (end == 0)
		return (count);
	else
		return (end);
}
