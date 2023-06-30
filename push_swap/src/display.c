/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:47:43 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/29 17:28:24 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	put_spaces(int nb)
{
	int	i;
	int	n;
	int	nbr;

	nbr = nb;
	i = 1;
	if (nb < 0)
		i++;
	while (nb / 10 != 0)
	{
		nb /= 10;
		i++;
	}
	if (i % 2 == 1)
		ft_putstr_fd(" ", 1);
	n = 0;
	while (++n < (16 - i) / 2)
		ft_putstr_fd(" ", 1);
	ft_putnbr_fd(nbr, 1);
	n = -1;
	while (++n < (16 - i) / 2)
		ft_putstr_fd(" ", 1);
}

void	display_data_1(t_array *arr)
{
	if (arr->used)
	{
		ft_putstr_fd("|", 1);
		put_spaces(arr->val);
		ft_putstr_fd("|", 1);
	}
	else
		ft_putstr_fd("|\t-\t|", 1);
}

void	display_data_2(t_array *arr)
{
	if (arr->used)
		put_spaces(arr->val);
	else
		ft_putstr_fd("\t-\t", 1);
}

void	display_lists(t_data *data)
{
	int		i;

	i = -1;
	ft_putstr_fd("\n    List a:\t      List b:", 1);
	ft_putstr_fd("\n---------------------------------\n", 1);
	while (++i < data->total)
	{
		display_data_1(&data->arr_a[i]);
		display_data_2(&data->arr_b[i]);
		ft_putstr_fd("|\n", 1);
	}
	ft_putstr_fd("---------------------------------\n", 1);
	// if (data->is_sorted == 1)
	// 	ft_putstr_fd("\nThe list is sorted!\n\n", 1);
}
