/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 21:30:38 by rcarette          #+#    #+#             */
/*   Updated: 2016/12/16 21:31:02 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*modify_dup(char **param, char character)
{
	int		ite;
	int		size_character;
	char	*new_string;
	int		jte;

	ite = -1;
	jte = -1;
	size_character = 0;
	while ((*param)[++ite])
		if ((*param)[ite] != character)
			++size_character;
	ite = -1;
	if (!(new_string = (char *)malloc(sizeof(char) * (size_character + 1))))
		exit(EXIT_FAILURE);
	ft_bzero(new_string, (size_character + 1));
	while ((*param)[++ite])
		if ((*param)[ite] != character)
			new_string[++jte] = (*param)[ite];
	ft_memdel((void **)param);
	return (new_string);
}
