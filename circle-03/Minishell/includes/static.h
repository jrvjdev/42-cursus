#ifndef STATIC_H
# define STATIC_H

# include "string.h"

typedef struct	s_token
{
	char			**args; //args[0] = cmd, args[...]  = arguments 
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