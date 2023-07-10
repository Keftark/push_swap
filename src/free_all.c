/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:21:13 by cpothin           #+#    #+#             */
/*   Updated: 2023/07/01 15:25:15 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	free_arrays(t_data *data)
{
	free(data->arr_a);
	free(data->arr_b);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	free_all(t_data *data, char **split)
{
	free_split(split);
	free_arrays(data);
	return (0);
}
