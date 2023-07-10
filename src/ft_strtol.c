/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:36:57 by cpothin           #+#    #+#             */
/*   Updated: 2023/07/01 10:34:18 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	charmap(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (127);
}

long	ft_strtol(const char *nptr, char **endptr)
{
	int		neg;
	long	result;
	char	digit;

	neg = 0;
	result = 0;
	if (*nptr == '-')
		if (*nptr++ == '-')
			neg = 1;
	digit = charmap(*nptr);
	while (digit < 10)
	{
		digit = charmap(*nptr++);
		result = (result * 10) + digit;
		if (result < 0)
		{
			if (endptr)
				*endptr = (char *)nptr;
			return (LONG_MAX + neg);
		}
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (result + (result * -2 * neg));
}

/*long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int		neg;
	long	result;
	char	digit;

	if (base < 0 || base > 36)
		return (0);
	neg = 0;
	result = 0;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			neg = 1;
	base = getbase(&nptr, base);
	while ((digit = charmap(*nptr++)) < base)
		if ((result = (result * base) + digit) < 0)
		{
			if (endptr)
				*endptr = (char *)nptr;
			return (LONG_MAX + neg);
		}
	if (endptr)
		*endptr = (char *)nptr;
	return (result + (result * -2 * neg));
}*/
