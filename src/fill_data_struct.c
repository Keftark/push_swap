/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:37:55 by cpothin           #+#    #+#             */
/*   Updated: 2023/07/01 10:39:07 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_digits(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	fill_indexes(t_data *data)
{
	int	min;
	int	index;
	int	i;
	int	to_mod;

	index = 1;
	to_mod = 0;
	while (index <= data->total)
	{
		min = data->max_value + 1;
		i = 0;
		while (i < data->total)
		{
			if (data->arr_a[i].val < min
				&& data->arr_a[i].val > data->min_value)
			{
				min = data->arr_a[i].val;
				to_mod = i;
			}
			i++;
		}
		data->arr_a[to_mod].index = index;
		data->min_value = data->arr_a[to_mod].val;
		index++;
	}
}

void	get_min_max(t_data *data)
{
	int	min;
	int	max;
	int	i;

	i = 0;
	min = data->arr_a[0].val;
	max = data->arr_a[0].val;
	while (i < data->total)
	{
		if (data->arr_a[i].val < min)
			min = data->arr_a[i].val;
		else if (data->arr_a[i].val > max)
			max = data->arr_a[i].val;
		i++;
	}
	data->min_value = min;
	data->max_value = max;
	if (get_digits(data->min_value) > get_digits(data->max_value))
		data->max_digits = get_digits(data->min_value);
	else
		data->max_digits = get_digits(data->max_value);
	data->min_value--;
	fill_indexes(data);
}

void	init_data(t_data *data, int nb)
{
	int	i;

	data->total = nb;
	data->calculations = 0;
	data->arr_a = (t_array *)malloc(sizeof(t_array) * nb);
	if (!data->arr_a)
		return (exit(0));
	data->arr_b = (t_array *)malloc(sizeof(t_array) * nb);
	if (!data->arr_b)
		return (exit(0));
	i = 0;
	while (i < nb)
	{
		data->arr_b[i].used = 0;
		data->arr_b[i].val = 0;
		i++;
	}
}
