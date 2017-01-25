/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:22:04 by rcarette          #+#    #+#             */
/*   Updated: 2016/12/22 21:51:33 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_delete_replace(char **s1, char **s2)
{
	char	*temporary;

	temporary = *s1;
	if (!(*s1 = ft_strdup(*s2)))
		exit(EXIT_FAILURE);
	free(temporary);
}

static int		ft_search(char *board, char **stock, char **line)
{
	char	*t_li;
	char	*t;

	if (!(t_li = ft_strchr(board, '\n')))
		return (0);
	*t_li = '\0';
	t = *line;
	if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(board)
						+ ft_strlen(t)) + 1)))
		return (-1);
	ft_strcpy(*line, t);
	ft_strcat(*line, board);
	free(t);
	*stock = ft_strdup(t_li + 1);
	return (1);
}

static void		ft_assembly(char **line, char *b)
{
	char	*t_li;

	if (*line == NULL)
	{
		if (!(*line = malloc(sizeof(char) * (ft_strlen(b) + 1))))
			return ;
		ft_strcpy(*line, b);
	}
	t_li = *line;
	if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(b)
						+ ft_strlen(t_li) + 1))))
		return ;
	ft_strcpy(*line, t_li);
	ft_strcat(*line, b);
	free(t_li);
}

static int		ft_search_stock(char **stock, char **line)
{
	char	*t_li;
	char	*temporary;

	t_li = ft_strchr(*stock, '\n');
	if (t_li == NULL)
	{
		ft_delete_replace(line, stock);
		free(*stock);
		*stock = NULL;
	}
	else
	{
		*t_li = '\0';
		ft_delete_replace(line, stock);
		temporary = *stock;
		if (!(*stock = ft_strdup(t_li + 1)))
			return (-1);
		free(temporary);
		temporary = NULL;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*stock = NULL;
	int				ret;
	char			board[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(*line = malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	ft_bzero(*line, BUFF_SIZE);
	if (stock)
		if (ft_search_stock(&stock, line))
			return (1);
	while ((ret = read(fd, board, BUFF_SIZE)) > 0)
	{
		board[ret] = '\0';
		if (ft_search(board, &stock, line))
			return (1);
		ft_assembly(line, board);
	}
	if (ret == 0 && ft_strlen(*line) >= 1)
		return (1);
	return (ret < 0 ? -1 : 0);
}
