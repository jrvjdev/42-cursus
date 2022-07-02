
#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

int		r_size(char *s);
void	_stradd(char **str, char *add);
int		_strcount_char(char *str, char l);
void	free_arrays(char **arr);
char	**buffer_into_array(char *str);
void	ft_dquote(char **output, char c);

void	print_arrays(char **a);
#endif