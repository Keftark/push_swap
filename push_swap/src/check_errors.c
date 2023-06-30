/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:25:44 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/29 09:14:24 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_numbers(char *str)
{
	long int	nb;
	char		*ptr;

	errno = 0;
	nb = ft_strtol(str, &ptr);
	if (errno != 0 || ptr == str) // || *ptr != '\0' <- suppression de cette condition... est-elle utile??
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

static int	check_if_exists(char *str, t_data *data)
{
	int		nb;
	int		i;

	nb = ft_atoi(str);
	i = 0;
	while (i < data->total)
	{
		if (data->arr_a[i].val == nb)
			return (1);
		i++;
	}
	return (0);
}

int	check_errors(char *str, t_data *data)
{
	if (check_numbers(str) == 0)
	{
		write(2, "Error\n\t", 7);
		ft_putstr_fd(str, 2);
		return (write(2, " is is not an int!", 18));
	}
	if (arg_error(str) == 1)
	{
		write(2, "Error\n\t", 7);
		ft_putstr_fd(str, 2);
		return (write(2, " <- You must enter only numbers!", 32));
	}
	if (check_if_exists(str, data) == 1)
	{
		write(2, "Error\n\t", 7);
		ft_putstr_fd(str, 2);
		return (write(2, " <- This number already exists!", 31));
	}
	return (0);
}
