/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strfuncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:59:33 by nsainton          #+#    #+#             */
/*   Updated: 2023/05/08 12:03:15 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	index;

	index = 0;
	while (*(src + index))
	{
		*(dest + index) = *(src + index);
		index ++;
	}
	*(dest + index) = 0;
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n && *(src + index))
	{
		*(dest + index) = *(src + index);
		index ++;
	}
	while (index < n)
	{
		*(dest + index) = 0;
		index ++;
	}
	return (dest);
}
