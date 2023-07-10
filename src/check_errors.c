/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:25:44 by cpothin           #+#    #+#             */
/*   Updated: 2023/07/10 09:25:19 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_numbers(char *str)
{
	long int	nb;
	char		*ptr;

	errno = 0;
	nb = ft_strtol(str, &ptr);
	if (errno != 0 || ptr == str)
		return (0);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

static int	arg_error(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = -1;
	if (str[i + 1] == '-')
		i++;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	return (0);
}

static int	check_if_exists(char *str, t_data *data, int index)
{
	int		nb;
	int		i;

	nb = ft_atoi(str);
	i = 0;
	while (i < index)
	{
		if (data->arr_a[i].val == nb)
			return (1);
		i++;
	}
	return (0);
}

int	check_errors(char *str, t_data *data, int index)
{
	if (check_numbers(str) == 0 || arg_error(str) == 1
		|| check_if_exists(str, data, index) == 1 || data->total == 1)
		return (write(2, "Error\n", 6));
	return (0);
}
