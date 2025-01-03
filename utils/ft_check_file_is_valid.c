/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_is_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:52:44 by lrecine-          #+#    #+#             */
/*   Updated: 2025/01/03 14:16:49 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	find(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_file_is_valid(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (find(file_line, ".ber"))
			{
				return ;
			}
		}
		file_line++;
	}
	printf("\033[1;31m🛑ERROR: file is not valid\033[0m");
	exit(1);
}
