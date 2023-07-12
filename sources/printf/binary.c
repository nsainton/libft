/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:37:29 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/13 00:49:36 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_bpad(char res[34], char flags[128], t_print *pads)
{
	*(pads->modifier) = 0;
	pads->beg = 0;
	pads->pad = ' ';
	pads->align = 'r';
	if (flags[48] && ! flags['.'])
		pads->pad = 48;
	if (flags['-'])
		pads->align = 'l';
	if (! (flags['#'] && *res) || *res == 48)
		return ;
	ft_strlcat(pads->modifier, "0b", 3);
}

static void	build_bres(t_pbuffer *buf, char res[34], char flags[128])
{
	t_print	pads;
	int		len;

	set_bpad(res, flags, &pads);
	len = (int)ft_strlen(res);
	buf->prec = max_int(buf->prec, len);
	buf->width = max_int(buf->width, buf->prec);
	print_res(buf, res, len, &pads);
}

void	put_bin(t_pbuffer *buf, va_list *ap, char flags[128])
{
	char	res[34];
	t_ull	arg;
	char	*tmp;

	tmp = res;
	*tmp = 0;
	arg = (t_ull)va_arg(*ap, unsigned int);
	put_pos(arg, &tmp, BIN);
	*tmp = 0;
	if (!(arg || buf->prec) && flags['.'])
		*res = 0;
	build_bres(buf, res, flags);
}
