/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:24:13 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/09 09:58:05 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*command_pre_system(t_command *invoker, t_command *this)
{
	char	*name;

	// printf("%s %s\n", __func__, this->name);
	if (this->next)
	{
		name = ft_strjoin(this->name, " ");
		name = ft_strjoin(name, this->next->pre_function(invoker, this->next));
	}
	else
		name = ft_strjoin(this->name, "");
	_command_free(this);
	return (name);
}

char	*get_cmd(char **paths, char *cmd)
{
	int		i;
	char	*inter;
	char	*cmd_path;

	i = 0;
	while (paths[i])
	{
		inter = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(inter, cmd);
		_memory().free(inter);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		_memory().free(cmd_path);
		i++;
	}
	return (NULL);
}

void	terminate(char *m)
{
	if (errno == 0)
		write(2, "Error\n", 6);
	else
		perror(m);
	exit(EXIT_FAILURE);
}

void	command_system(t_command *this)
{
	char	*name;
	char	**args;
	char	**paths;
	char	*path;
	int		test;
	pid_t	c_pid;

	test = 0;
	// printf("%s %s\n", __func__, this->name);
	if (this->next)
	{
		name = ft_strjoin(this->name, " ");
		name = ft_strjoin(name, this->next->pre_function(this, this->next));
	}
	else
		name = ft_strjoin(this->name, "");
	c_pid = fork();
	if (c_pid < 0)
		terminate("fork");
	if (c_pid == 0)
	{
		args = _string().split_string(name, " ");
		path = get_env("PATH")->value;
		paths = _string().split_string(path, ":");
		while (args[test])
			test++;
		args[test] = NULL;
		execve(get_cmd(paths, this->name), args, NULL);
	}
	wait(NULL);
	_command_free(this);
}
