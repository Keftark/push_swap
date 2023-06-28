/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:57:52 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/28 17:38:48 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_list(t_array *arr, int n)
{
	int	swap;

	if (!arr[0].used || !arr[1].used)
		return ;
	swap = arr[1].val;
	arr[1].val = arr[0].val;
	arr[0].val = swap;
	if (n == 0)
		ft_putstr_fd("\nsa", 1);
	else if (n == 1)
		ft_putstr_fd("\nsb", 1);
	else if (n == 2)
		ft_putstr_fd("\nss", 1);
}

void	push_list(t_array *arr1, t_array *arr2, int n)
{
	int	i;

	ft_putstr_fd("\npushing...\n", 1);
	i = 0;
	if (!arr2[0].used)
		return ;
	while (arr1[i].used)
	{
		arr1[i + 1].val = arr1[i].val;
		i++;
	}
	ft_putstr_fd("\n0\n", 1);
	arr1[i].used = 1;
	arr1[0].val = arr2[0].val;
	i = 1;
	while (arr1[i].used)
	{
		arr1[i - 1].val = arr1[i].val;
		i++;
	}
	arr1[i - 1].val = 0;
	arr1[i - 1].used = 0;
	if (n == 0)
		ft_putstr_fd("\npa", 1);
	else if (n == 1)
		ft_putstr_fd("\npb", 1);
}

void	rotate_list(t_array *arr, int n, int max)
{
	int	swap_val;
	int	i;

	if (!arr[0].used)
		return ;
	swap_val = arr[0].val;
	i = 0;
	while (++i < max && arr[i].used)
		arr[i - 1].val = arr[i].val;
	arr[i - 1].val = swap_val;
	if (n == 0)
		ft_putstr_fd("\nra", 1);
	else if (n == 1)
		ft_putstr_fd("\nrb", 1);
	else if (n == 2)
		ft_putstr_fd("\nrr", 1);
}

void	rev_rotate_list(t_array *arr, int n, int max)
{
	int	swap_val;
	int	i;

	i = 0;
	if (!arr[0].used)
		return ;
	while (i < max && arr[i].used)
	{
		i++;
		if (i < max && arr[i].used)
		{
			arr[i - 1].val = arr[i].val;
		}
		else if (i < max)
			swap_val = arr[i].val;
	}
	arr[0].val = swap_val;
	if (n == 0)
		ft_putstr_fd("\nrra", 1);
	else if (n == 1)
		ft_putstr_fd("\nrrb", 1);
	else if (n == 2)
		ft_putstr_fd("\nrrr", 1);
}
