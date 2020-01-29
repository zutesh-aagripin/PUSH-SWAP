/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:51:19 by aagripin          #+#    #+#             */
/*   Updated: 2019/11/11 21:22:44 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

char		*ft_rewrite(t_list_c **list)
{
	char	*string;
	int		listsize;
	t_list_c*ptr;

	ptr = *list;
	if (*list == NULL)
		return (NULL);
	listsize = ft_list_size(*list);
	if (!(string = ft_memalloc(listsize + 1)))
	{
		ft_list_clear(list);
		return (NULL);
	}
	while (ptr != NULL)
	{
		string = ft_strcat(string, ptr->data);
		ptr = ptr->next;
	}
	ft_list_clear(list);
	return (string);
}

int			ft_next(char **line, char **data, t_list_c **list)
{
	char*end;

	if ((end = ft_strchr(*data, '\n')))
	{
		*end = '\0';
		end++;
		ft_list_push_back(list, *data);
		if (*end)
			if (!(end = ft_strdup(end)))
				return (0);
		free(*data);
		*data = NULL;
		if (*end)
			*data = end;
		if ((*line = ft_rewrite(list)) != NULL)
			return (1);
	}
	ft_list_push_back(list, *data);
	free(*data);
	*data = NULL;
	return (0);
}

int			ft_readline(int fd, t_list_c **list, char **ptr)
{
	char	buffer[BUFF_SIZE + 1];
	char	*end;
	int		ret;

	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if ((end = ft_strchr(buffer, '\n')))
		{
			*end = '\0';
			end++;
			if (*end)
				if (!(*ptr = ft_strdup(end)))
					return (-1);
			ft_list_push_back(list, buffer);
			break ;
		}
		else
			ft_list_push_back(list, buffer);
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	t_list_c		*list;
	static char		*storage;

	if (fd < 0 || !(line))
		return (-1);
	list = NULL;
	if (storage != NULL && *storage != '\0')
		if ((ft_next(line, &storage, &list)))
			return (1);
	if ((ft_readline((int)fd, &list, &storage)) == -1)
		return (-1);
	if ((*line = ft_rewrite(&list)) != NULL)
		return (1);
	return (0);
}
