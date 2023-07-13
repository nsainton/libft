/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:45:38 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/13 03:33:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_color(t_color *colors, char *color, char *code)
{
	colors->color = color;
	colors->code = code;
}

static void	init_colors(t_color	colors[COLORS_NB])
{
	add_color(colors, "black", BLK);
	add_color(colors + 1, "red", RED);
	add_color(colors + 2, "green", GRN);
	add_color(colors + 3, "blue", BLU);
	add_color(colors + 4, "magenta", MAG);
	add_color(colors + 5, "cyan", CYN);
	add_color(colors + 6, "white", WHT);
	add_color(colors + 7, "eoc", CRESET);
}

static t_color	*get_colors(void)
{
	static t_color	colors[COLORS_NB] = {0};
	char			nullelem[30];

	ft_bzero(nullelem, sizeof * colors);
	if (! ft_memcmp(nullelem, colors, sizeof * colors))
		init_colors(colors);
	return (colors);
}

static char	*get_color(char *color)
{
	size_t	index;
	t_color	*colors;
	char	nullelem[30];

	ft_bzero(nullelem, sizeof * colors);
	index = 0;
	colors = get_colors();
	while (index < COLORS_NB && ft_memcmp(nullelem, \
	colors + index, sizeof * colors))
	{
		if (! ft_strcmp((colors + index)->color, color))
			return ((colors + index)->code);
		index ++;
	}
	return (NULL);
}

int	print_color_buf(t_pbuffer *buf, char *color)
{
	char	*code;

	code = get_color(color);
	if (! code)
		return (NO_COLOR);
	if (buf->len + ft_strlen(code) > PBUFFER_SIZE - 1)
		flush(buf);
	add_str(buf, code);
	return (COLOR_EXISTS);
}
