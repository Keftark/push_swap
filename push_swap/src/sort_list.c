/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:38:08 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/30 15:49:57 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sorted(t_data *data)
{
	int	i;
	i = -1;
	if (data->arr_b[0].used)
		return (0);
	while (++i < data->total)
	{
		if (!data->arr_a[i].used)
			return (0);
		if (i + 1 < data->total && data->arr_a[i + 1].used)
			if (data->arr_a[i].val > data->arr_a[i + 1].val)
				return (0);
	}
	data->is_sorted = 1;
	ft_putstr_fd("\nThe list is sorted!\n\n", 1);
	return (1);
}

void	sort_3(t_data *data)
{
	if (data->arr_a[0].val > data->arr_a[1].val
		&& data->arr_a[1].val > data->arr_a[2].val)
	{
		rotate_list(data->arr_a, 0, data);
		swap_list(data->arr_a, 0, data);
		//display_lists(data);
	}
	if (data->arr_a[0].val < data->arr_a[1].val
		&& data->arr_a[2].val < data->arr_a[0].val)
	{
		rev_rotate_list(data->arr_a, 0, data);
		//display_lists(data);
	}
	if (data->arr_a[1].val < data->arr_a[2].val
		&& data->arr_a[0].val > data->arr_a[2].val)
	{
		rotate_list(data->arr_a, 0, data);
		//display_lists(data);
	}
	if (data->arr_a[0].val > data->arr_a[1].val)
	{
		swap_list(data->arr_a, 0, data);
		//display_lists(data);
	}
	if (data->arr_a[2].val < data->arr_a[0].val)
	{
		rotate_list(data->arr_a, 0, data);
		//display_lists(data);
	}
	else if (data->arr_a[2].val < data->arr_a[1].val)
	{
		rev_rotate_list(data->arr_a, 0, data);
		swap_list(data->arr_a, 0, data);
		//display_lists(data);
	}
	if (data->arr_a[0].val > data->arr_a[2].val)
	{
		rotate_list(data->arr_a, 0, data);
		//display_lists(data);
	}
	// if (check_sorted(data) == 0)
	// 	sort_3(data);
}

void	sort_5(t_data *data) // sorting 4 or 5
{
	int	mods;
	int	i;

	i = 0;
	mods = 0;
	push_list(data->arr_b, data->arr_a, 1, data);
	push_list(data->arr_b, data->arr_a, 1, data);
	sort_3(data);
	while (mods < 2)
	{
		if (data->arr_b[0].val == data->max_value)
		{
			push_list(data->arr_a, data->arr_b, 0, data);
			rotate_list(data->arr_a, 0, data);
		}
		else
		{
			while (data->arr_b[0].val > data->arr_a[0].val && ++i > 0)
				rotate_list(data->arr_a, 0, data);
			push_list(data->arr_a, data->arr_b, 0, data);
			while (i > 0)
			{
				rev_rotate_list(data->arr_a, 0, data);
				i--;
			}
		}
		mods++;
	}
}


void	start_sorting(t_data *data)
{
	if (check_sorted(data) == 1)
		return ;
	if (data->total == 2)
	{
		swap_list(data->arr_a, 0, data);
		data->is_sorted = 1;
	}
	else if (data->total == 3)
		sort_3(data);
	else if (data->total <= 5)
		sort_5(data);
	else
		sort_big(data);
	//display_lists(data);
}
