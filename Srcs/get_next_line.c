/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:29:47 by araramya          #+#    #+#             */
/*   Updated: 2021/02/22 16:23:19 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int		get_next_line(int fd, char **line)
{
	char			*buffer;
	int				readed;
	static char		*rem_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (!(buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1)))
		return (-1);
	while ((readed = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[readed] = '\0';
		rem_line = ft_strjoin(rem_line, buffer);
		if (ft_str_endline(rem_line))
			break ;
	}
	free(buffer);
	if (readed < 0)
		return (-1);
	*line = ft_remline(rem_line);
	rem_line = ft_clearrem(rem_line);
	if (readed == 0 && !rem_line)
		return (0);
	return (1);
}




