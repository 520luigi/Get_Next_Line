/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 21:01:50 by szheng            #+#    #+#             */
/*   Updated: 2018/07/14 16:20:48 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *subs, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	if (*subs == '\0')
		return ((char *)s);
	while (s[j] && j < len)
	{
		k = j;
		while (subs[i] == s[k] && i + j < len)
		{
			if (subs[i + 1] == '\0')
				return ((char *)&s[j]);
			i++;
			k++;
		}
		i = 0;
		j++;
	}
	return (NULL);
}
