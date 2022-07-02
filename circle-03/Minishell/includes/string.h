/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:35:24 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/02 11:40:15 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <unistd.h>
# include <stdbool.h>

# include "char.h"
# include "memory.h"

typedef struct s_hashmap
{
	char	*key;
	char	*value;
}	t_hashmap;

typedef struct s_string
{
	size_t	(*length)(char *string);
	int		(*equals)(char *string_1, char *string_2);
	int		(*contains)(char *string_1, char *string_2);
	int		(*index_of)(char *string_1, char *string_2);
	int		(*beginning_equals)(char *string_1, char *string_2);
	void	(*copy)(char *dst, char *src);
	void	(*cat)(char *string, char *to_cat);
	void	(*copy_at)(char *dst, char *src, size_t size);
	char	*(*dup)(const char *string);
	char	*(*dup_at)(const char *string, size_t size);
	char	**(*split_char)(char *string, char separator);
	char	**(*split_string)(char *string, char *separator);
}	t_string;

bool		_isquote(char c);
t_string	_string(void);

size_t		_string_length(char *string);
int			_string_equals(char *string_1, char *string_2);
int			_string_contains(char *string_1, char *string_2);
int			_string_index_of(char *string_1, char *string_2);
int			_string_beginning_equals(char *string_1, char *string_2);

char		*_string_dup(const char *string);
char		*_string_dup_at(const char *string, size_t size);

void		_string_copy(char *dst, char *src);
void		_string_cat(char *string, char *to_cat);
void		_string_copy_at(char *dst, char *src, size_t size);

char		**_string_split_char(char *string, char separator);
char		**_string_split_string(char *string, char *separator);

t_hashmap	*_string_new_hashmap(char *string);

#endif
