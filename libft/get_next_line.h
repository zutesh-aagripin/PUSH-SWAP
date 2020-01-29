/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagripin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:37:39 by aagripin          #+#    #+#             */
/*   Updated: 2019/10/28 16:07:13 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 16328

typedef struct		s_list_fd
{
	char			*data;
	struct s_list_fd*next;
	int				fd;
}					t_list_fd;

int					get_next_line(const int fd, char **line);

#endif
