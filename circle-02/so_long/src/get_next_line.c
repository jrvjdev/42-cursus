/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:10:58 by joaribei          #+#    #+#             */
/*   Updated: 2022/03/14 15:10:59 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

ssize_t	ft_copy_buffer_aux(ssize_t index2, char *s1, char *s2, int *nl)
{
	ssize_t	index1;

	*nl = 0;
	index1 = 0;
	while (s1[index1])
	{
		if (s1 && s2)
			s2[index1 + index2] = s1[index1];
		if (s1[index1++] == 10)
			if (++*nl)
				break ;
	}
	return (index1);
}

char	*ft_copy_buffer(int *nl, char *buffer, char *ptr, char *temp)
{
	ssize_t			index1;
	ssize_t			index2;

	index2 = 0;
	index1 = ft_copy_buffer_aux(0, buffer, 0, nl);
	while (ptr && ptr[index2])
		index2++;
	temp = new_maloc((index1 + index2 + 1) * sizeof(char));
	index2 = -1;
	while (++index2 > -1 && ptr && ptr[index2])
		temp[index2] = ptr[index2];
	index1 = ft_copy_buffer_aux(index2, buffer, temp, nl);
	temp[index1 + index2] = '\0';
	index2 = -1;
	while (buffer[index1 + ++index2])
		buffer[index2] = buffer[index1 + index2];
	while (buffer[index2])
		buffer[index2++] = 0;
	free_maloc(ptr);
	return (temp);
}

char	*get_next_line(int fd)
{
	ssize_t			length;
	char			*ptr;
	int				nl;
	static char		buffer[BUFFER_SIZE + 1];

	nl = 0;
	ptr = 0;
	if (fd < 0)
		return (0);
	while (1)
	{
		ptr = ft_copy_buffer(&nl, buffer, ptr, 0);
		if (nl)
			return (ptr);
		length = read(fd, buffer, BUFFER_SIZE);
		if (!length && *ptr)
			return (ft_copy_buffer(&nl, buffer, ptr, 0));
		if (length < 1)
			break ;
	}
	free_maloc(ptr);
	return (0);
}
