/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:37:55 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/28 12:15:29 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
}

void	init_data(t_data *data, int nb)
{
	int	i;

	data->total = nb;
	data->calculations = 0;
	get_min_max(data);
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