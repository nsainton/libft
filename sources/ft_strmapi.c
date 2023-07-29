/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:40:45 by nsainton          #+#    #+#             */
/*   Updated: 2023/07/29 10:14:51 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	To prevent integer promotion from hapenning too often and to comply with
	historical reasons for which char function takes and return an integer
	the function to be applied is a function that takes and return an integer
*/
char	*ft_strmapi(char const *s, int (*f) (unsigned int, int))
{
	unsigned int	i;
	char			*ns;

	if (s == NULL || f == NULL)
		return (NULL);
	ns = (char *)malloc((ft_strlen(s) + 1) * sizeof(*ns));
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(ns + i) = f(i, *(s + i));
		i ++;
	}
	*(ns + i) = 0;
	return (ns);
}
