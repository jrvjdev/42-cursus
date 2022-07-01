/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:35:24 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 10:42:55 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <unistd.h>
# include "malloc.h"

typedef struct s_hashmap
{
	char	*key;
	char	*value;
}	t_hashmap;

typedef struct s_string
{
	int		(*length)(char *string);
	int		(*equals)(char *string_1, char *string_2);
	int		(*contains)(char *string_1, char *string_2);
	int		(*index_of)(char *string_1, char *string_2);
	int		(*beginning_equals)(char *string_1, char *string_2);
	char	**(*split_char)(char *string, char separator);
	char	**(*split_string)(char *string, char *separator);
	char	*(*dup)(const char *string);
}	t_string;

t_string	string(void);

int			length(char *string);
int			equals(char *string_1, char *string_2);
int			contains(char *string_1, char *string_2);
int			index_of(char *string_1, char *string_2);
int			beginning_equals(char *string_1, char *string_2);

char		**split_char(char *string, char separator);
char		**split_string(char *string, char *separator);
char		*dup(const char *string);

t_hashmap	*new_hashmap(char *string);

#endif
