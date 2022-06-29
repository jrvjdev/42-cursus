/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:27:36 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/12 19:43:19 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
* structs
*/
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

/*
* functions list
*/
void		push(t_list **src, t_list **dest, int option);
void		swap(t_list **stack, int option);
void		ss(t_list **stack_a, t_list **stack_b, int option);
int			is_integer(char *av);
int			is_digit(int c);
int			is_white_space(int c);
long		ft_atoi(const char *str);
int			ft_split_atoi(t_list **stack, char **str);
t_list		*lst_new(int content);
t_list		*lst_last(t_list *lst);
void		rotate(t_list **stack, int option);
void		rr(t_list **stack_a, t_list **stack_b, int option);
void		reverse_rotate(t_list **stack, int option);
void		rrr(t_list **stack_a, t_list **stack_b, int option);
int			lst_size(t_list *lst);
int			lst_sorted(t_list *lst);
void		lst_delone(t_list *lst);
void		lst_clear(t_list **lst);
void		lst_clear_all(t_list **lst_a, t_list **lst_b);
void		lst_add_back(t_list **lst, t_list *new);
void		lst_add_front(t_list **lst, t_list *new);

#endif
