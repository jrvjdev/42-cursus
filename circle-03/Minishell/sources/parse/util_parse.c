#include "../includes/minishell.h"

char		*parse_var_env(char *str) //returns $PWD into (User/v/Home)
{
	t_hashmap	*lst;

	lst = get_shell()->env;
	while (lst)
	{
		// printf("Search |%s|%s|\n", str, lst->name);
		if (_string().equals(str, lst->key))
			return (lst->value);
		// lst = lst->next; //NOT A LINK LIST
	}
	return ("");
}


void	dollar_for_money(char **out, char **str)
{
	char	*tmp;
	int		i;
	int		j;

	i = _string().length(*out);
	j = 0;
	(*str)++;
	tmp = NULL;
	if (**str == '?') //get exit code
	{
		(*str)++;
		tmp = _string()._string_itoa(get_shell()->ec);
		while (tmp[j])
			(*out)[i++] = tmp[j++];
	}
	else //check for envp and valiadte no $$ || $"look" (TO-DO function)
	{
		while ((*str)[j] != '$' && !_char().is_whitespace((*str)[j]) && !_string().isquote((*str)[j]) && (*str)[j])
			j++;
		tmp = _string_dup_at(*str, j); //copy until j
		// tmp = ft_strldup(*str, j); //copy until j
		(*str) += j;
		printf("(dollar_for_money)tmp =%s\n", tmp);
		tmp = parse_var_env(tmp);
		j = 0;
		while (tmp[j])
			(*out)[i++] = tmp[j++];
	}
	// printf("OUTPUT is %s\n", *out);
}

void	ft_squote(char **out, char **str)
{
	int	i;

	i = _string().length(*out);
	(*str)++;
	while (**str != '\'' && **str)
			(*out)[i++] = *(*str)++;
}

void	ft_db_quote(char **out, char **str)
{
	int	i;

	i = 0;
	(*str)++;
	while (**str != '"' && **str)
	{
		i = _string().length(*out);
		if (**str == '$' && (**str + 1 != '\'' || **str + 1 != '"')) //edge case
			dollar_for_money(out, str);
		else
			(*out)[i] = *(*str)++;
	}
}

// _string().parse_array
char	*parse_array(char *str)
{
	char	*out;
	int 	i;

	out = _memory().malloc(sizeof(char) * 400); //we dunno what the potential size can be
	i = 0;
	while (*str)
	{
		i = _string().length(out);
		if (*str == '\'')
			ft_squote(&out, &str);
		else if (*str == '"')
			ft_db_quote(&out, &str);
		else if (*str == '$')
			dollar_for_money(&out, &str);
		else
		{
			out[i] = *str;
			str++;
		}
	}
	out[_string().length(out) + 1] = 0;
	return (out);
}


/* to watch out for
* echo / $PWD'out' / $PWD$USR / $PWDout / $'this'
* echo "$PWD" / '$PWD' / "$'PWD'"

*/
