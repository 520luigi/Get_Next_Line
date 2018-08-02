/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:37:05 by szheng            #+#    #+#             */
/*   Updated: 2018/07/14 15:02:27 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *subs)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (subs[len])
		len++;
	if (len == 0)
		return ((char *)s);
	while (s[i])
	{
		while (subs[j] == s[i + j])
		{
			if (j == len - 1)
				return ((char *)s + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
