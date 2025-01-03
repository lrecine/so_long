/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:54:26 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/03 14:17:08 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_message_error(void)
{
	perror("\033[1;31m🛑ERROR:\033[0m");
	exit(1);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char	**get_map(char *fmap)
{
	char	*line;
	char	*all_lines;
	int		fd;

	line = "";
	all_lines = ft_strdup("");
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		ft_message_error();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		ft_message_error();
	return (ft_split(all_lines, '\n'));
}
