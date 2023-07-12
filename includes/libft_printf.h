/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:39:23 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/12 23:42:22 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include <stdarg.h>
# ifdef PBUFFER_SIZE
#  undef PBUFFER_SIZE
# endif
# define PBUFFER_SIZE 1000
# define FLAGS "# +-0"
# define SPECIFIERS "cspdiuxX%"
# define P_CONV "cspdiuxX"
# define ADMITTED "c;s;p;d;i;u;x;X;%;"
# define SEPARATOR ';'

typedef struct s_pbuffer
{
	char			buffer[PBUFFER_SIZE];
	int				len;
	int				width;
	int				prec;
	intptr_t		fd;
	int				printed;
	unsigned char	str:1;
}				t_pbuffer;

typedef struct s_print
{
	char	modifier[3];
	char	beg;
	char	pad;
	char	align;
}				t_print;

typedef enum e_pflags
{
	SHARP = 1 << 0,
	SPACE = 1 << 1,
	PLUS = 1 << 2,
	DASH = 1 << 3,
	ZERO = 1 << 4,
	DOT = 1 << 5
}				t_pflags;

/*
Think about using the enum in ft_printf
instead of the array of chars
*/

typedef void	(*t_pfunc)(t_pbuffer *, va_list *, char[128]);

#endif
