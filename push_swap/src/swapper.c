/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:57:52 by cpothin           #+#    #+#             */
/*   Updated: 2023/07/01 15:00:17 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_list(t_array *arr, int n, t_data *data)
{
	int	swap;

	if (!arr[0].used || !arr[1].used)
		return ;
	swap = arr[1].val;
	arr[1].val = arr[0].val;
	arr[0].val = swap;
	if (n == 0)
		ft_putstr_fd("sa\n", 1);
	else if (n == 1)
		ft_putstr_fd("sb\n", 1);
	else if (n == 2)
		ft_putstr_fd("ss\n", 1);
	if (n != 2)
		data->calculations++;
}

void	push_list(t_array *arr1, t_array *arr2, int n, t_data *data)
{
	int	i;

	i = data->total;
	if (!arr2[0].used)
		return ;
	if (!arr1[0].used)
		arr1[0].used = 1;
	else
		while (--i > 0)
			if (arr1[i - 1].used)
				copy_number(arr1, arr1, i - 1, i);
	copy_number(arr2, arr1, 0, 0);
	i = 0;
	while (++i < data->total && arr2[i].used)
		copy_number(arr2, arr2, i, i - 1);
	empty_number(arr2, i - 1);
	if (n == 0)
		ft_putstr_fd("pa\n", 1);
	else if (n == 1)
		ft_putstr_fd("pb\n", 1);
	data->calculations++;
}

void	rotate_list(t_array *arr, int n, t_data *data)
{
	int	swap_val;
	int	swap_index;
	int	i;

	if (!arr[0].used)
		return ;
	swap_val = arr[0].val;
	swap_index = arr[0].index;
	i = 0;
	while (++i < data->total && arr[i].used)
		copy_number(arr, arr, i, i - 1);
	arr[i - 1].val = swap_val;
	arr[i - 1].index = swap_index;
	if (n == 0)
		ft_putstr_fd("ra\n", 1);
	else if (n == 1)
		ft_putstr_fd("rb\n", 1);
	else if (n == 2)
		ft_putstr_fd("rr\n", 1);
	if (n != 2)
		data->calculations++;
}

void	rev_rotate_list(t_array *arr, int n, t_data *data)
{
	int	swap_val;
	int	i;

	i = data->total - 1;
	if (!arr[0].used)
		return ;
	swap_val = get_last_value(arr, data->total);
	while (i > 0)
	{
		if (i > 0 && arr[i].used)
			copy_number(arr, arr, i - 1, i);
		i--;
	}
	arr[0].val = swap_val;
	if (n == 0)
		ft_putstr_fd("rra\n", 1);
	else if (n == 1)
		ft_putstr_fd("rrb\n", 1);
	else if (n == 2)
		ft_putstr_fd("rrr\n", 1);
	if (n != 2)
		data->calculations++;
}
