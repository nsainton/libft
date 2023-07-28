/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 04:34:33 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/28 19:31:40 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tstr_addchar(t_str *str, int c)
{
	if (str->len >= str->size - 1)
		return (1);
	*(str->str + str->len) = c;
	str->len += 1;
	*(str->str + str->len) = 0;
	return (0);
}

int	tstr_addchar_realloc(t_str **str, int c)
{
	t_str	*tmp;

	if (! tstr_addchar(*str, c))
		return (EXIT_SUCCESS);
	tmp = tstr_realloc(*str, 2 * (*str)->size);
	if (! tmp)
		return (EXIT_FAILURE);
	*str = tmp;
	return (tstr_addchar(*str, c));
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
