/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:03:40 by rcarette          #+#    #+#             */
/*   Updated: 2016/12/11 14:54:06 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		alloc_insert(char **str, long int n, int size, int negative)
{
	*str = (char *)malloc(sizeof(char) * (size + 1));
	if (*str)
	{
		(*str)[size] = '\0';
		while (n > 9)
		{
			(*str)[--size] = (n % 10) + '0';
			n = (n / 10);
		}
		(*str)[--size] = (n % 10) + '0';
		(negative == 1) ? (*str)[--size] = '-' : 0;
	}
	else
		*str = NULL;
}

char			*ft_itoa(long long int n)
{
	int			size;
	char		*str;
	long int	number;
	long int	number_temp;
	int			negative;

	size = 1;
	negative = 0;
	number = (long int)n;
	if (n < 0)
	{
		size++;
		number = (-number);
		negative = 1;
	}
	number_temp = number;
	while (number > 9)
	{
		number = (number / 10);
		size = (size + 1);
	}
	alloc_insert(&str, number_temp, size, negative);
	return (str);
}
