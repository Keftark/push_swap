/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 08:17:48 by cpothin           #+#    #+#             */
/*   Updated: 2023/07/01 15:00:17 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	copy_number(t_array *arr_from, t_array *arr_to, int from, int to)
{
	arr_to[to].val = arr_from[from].val;
	arr_to[to].index = arr_from[from].index;
	arr_to[to].used = 1;
}

void	empty_number(t_array *arr, int n)
{
	arr[n].used = 0;
}

int	get_last_value(t_array *arr, int max)
{
	int	i;

	i = max - 1;
	while (i > 0)
	{
		if (arr[i].used)
			return (arr[i].val);
		i--;
	}
	return (0);
}
