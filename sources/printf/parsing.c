/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:33:37 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/13 03:48:45 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_conv(int *width, int *prec, const char **conv, char flags[128])
{
	ft_bzero(flags, 128);
	while (ft_strchr(FLAGS, **conv) != NULL)
	{
		flags[(int)**conv] = 1;
		*conv += 1;
	}
	*width = ft_atoi(*conv);
	while (ft_strchr(DEC, **conv) != NULL)
		*conv += 1;
	if (**conv == '.')
	{
		flags['.'] = 1;
		*conv += 1;
	}
	if (**conv == '-')
		conv += 1;
	*prec = ft_atoi(*conv);
	while (ft_strchr(DEC, **conv))
		*conv += 1;
}

void	loop(t_pbuffer *buf, const char **conv)
{
	char	color[COLOR_LEN + 1];
	char	*end_copy;
	int		color_printed;

	color_printed = NO_COLOR;
	end_copy = NULL;
	while (**conv && **conv != '%')
	{
		if (**conv == '{')
		{
			end_copy = strncpy_until(color, *conv + 1, '}', COLOR_LEN);
			color_printed = print_color_buf(buf, color);
		}
		if (color_printed == COLOR_EXISTS)
		{
			*conv += (end_copy - color) + 2;
			color_printed = NO_COLOR;
			continue ;
		}
		add_char(buf, **conv);
		*conv += 1;
	}
	if (**conv == '%')
		*conv += 1;
}
