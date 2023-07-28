/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:34:33 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/28 07:55:33 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tstr_addchar(t_str *str, char c)
{
	if (str->len >= str->size - 1)
		return (1);
	*(str->str + str->len) = c;
	str->len += 1;
	*(str->str + str->len) = 0;
	return (0);
}

size_t	tstrncat(t_str *str, const char *s, size_t bytes)
{
	size_t	added;
	size_t	i;

	if (str->len >= str->size - 1)
		return (0);
	if (bytes + str->len >= str->size - 1)
		bytes = str->size - str->len - 1;
	added = bytes;
	i = 0;
	while (i < bytes && *(s + i))
	{
		*(str->str + str->len) = *(s + i);
		str->len += 1;
		i ++;
	}
	*(str->str + str->len) = 0;
	return (added);
}
