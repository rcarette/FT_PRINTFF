/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:25:34 by mleroy            #+#    #+#             */
/*   Updated: 2016/12/31 08:36:24 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getwords_number(char *string, char character)
{
	int		words_number;
	int		i;

	words_number = 0;
	i = 0;
	string = ft_strtrim(string);
	while (string[i])
	{
		if (string[i] != character)
		{
			++words_number;
			while (string[i] != character && string[i] != '\0')
				++i;
		}
		else
			++i;
	}
	ft_memdel((void **)&string);
	return (words_number);
}

static void		ft_malloc_column(char ***board, char *s1, char characte, int i)
{
	char	*string;
	int		j;
	int		words_size;

	j = -1;
	string = ft_strtrim(s1);
	while (string[i])
	{
		if (string[i] != characte)
		{
			words_size = 0;
			while (string[i] != characte && string[i] != '\0')
			{
				++words_size;
				++i;
			}
			(*board)[++j] = (char *)malloc(sizeof(char) * (words_size + 1));
			ft_bzero((*board)[j], (words_size + 1));
		}
		else
			++i;
	}
	ft_memdel((void **)&string);
}

static void		ft_insert_charact(char ***board, char *s1, char charact, int i)
{
	char	*string;
	int		j;
	int		ite;

	j = -1;
	string = ft_strtrim(s1);
	while (string[i])
	{
		if (string[i] != charact)
		{
			++j;
			ite = -1;
			while (string[i] != charact && string[i] != '\0')
			{
				(*board)[j][++ite] = string[i];
				++i;
			}
		}
		else
			++i;
	}
	(*board)[++j] = NULL;
	ft_memdel((void **)&string);
}

char			**ft_strsplit(char *s1, char character)
{
	char	**board;

	if (!(board = (char **)malloc(sizeof(char *) *
		(ft_getwords_number(s1, character) + 1))))
		exit(EXIT_FAILURE);
	ft_malloc_column(&board, s1, character, 0);
	ft_insert_charact(&board, s1, character, 0);
	return (board);
}
