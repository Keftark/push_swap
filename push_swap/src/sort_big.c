/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:34:00 by cpothin           #+#    #+#             */
/*   Updated: 2023/07/01 10:38:09 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_arr_size(t_data *data)
{
	int	i;

	i = 0;
	if (!data->arr_a[0].used)
		return (data->total);
	while (data->arr_b[i].used)
		i++;
	return (i);
}

void	push_back(t_data *data)
{
	while (data->arr_b[0].used)
		push_list(data->arr_a, data->arr_b, 0, data);
}

void	ft_radix(t_data *data)
{
	int		max_bits;
	int		i;
	int		j;

	max_bits = 0;
	while ((data->total - 1) >> max_bits != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < data->total)
		{
			if (((data->arr_a[0].index >> i) & 1) == 1)
				rotate_list(data->arr_a, 0, data);
			else
				push_list(data->arr_b, data->arr_a, 1, data);
		}
		push_back(data);
	}
}
