#ifndef STATIC_H
# define STATIC_H

typedef struct	s_token
{
	char			*cmds;
	char			**args;
	struct s_token	*next;
}				t_token;

typedef struct s_minishell
{
	char		**envp;	//envp used for execution
	t_hashmap	*env;	//link_list to save envps
	t_token		*tkn;
	int			ec; //exitcode
}		t_shell;

t_shell	*get_shell(void);


# endif