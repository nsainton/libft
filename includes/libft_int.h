/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:01:17 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/12 23:42:52 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INT_H
# define LIBFT_INT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <sys/types.h>
# include "libft_printf.h"
# include "ansicolorcodes.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# ifdef FILES
#  undef FILES
# endif
# define FILES 123
# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	int				priority;
}				t_list;

typedef struct s_gline
{
	char	*line;
	size_t	line_index;
}				t_gline;

typedef struct s_str
{
	char	*str;
	size_t	len;
	size_t	size;
}				t_str;

typedef struct s_cstr
{
	const char	*str;
	size_t		index;
}				t_cstr;

typedef long long int			t_ll;

typedef t_ll					t_llong;

typedef unsigned long long int	t_ull;

typedef t_ull					t_ullong;

typedef signed long long int	t_sllong;

typedef t_sllong				t_sll;

typedef unsigned char			t_uchar;

typedef const t_uchar			t_cuchar;

typedef signed char				t_schar;

typedef const signed char		t_cschar;

typedef signed int				t_sint;

typedef unsigned int			t_uint;

typedef const int				t_cint;

typedef const char				t_cchar;

typedef const size_t			t_csizet;

typedef const t_ll				t_cllong;

typedef const void				t_cvoid;

typedef int						(*t_colorfunc)(t_cvoid *, t_cchar *, t_cint);

typedef void					(*t_delfunc)(void *);

typedef t_list					t_alloc;

typedef const t_list			t_clist;

#endif
