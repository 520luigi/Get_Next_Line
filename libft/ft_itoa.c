/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:52:00 by szheng            #+#    #+#             */
/*   Updated: 2018/07/14 17:31:58 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		tmp;

	len = ft_len(n) - 1;
	tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = tmp % 10 + '0';
	while (tmp /= 10)
	{
		len--;
		str[len] = tmp % 10 + '0';
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
