/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:00:38 by cpothin           #+#    #+#             */
/*   Updated: 2023/07/10 09:25:07 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	add_list(t_array *arr, int nbr, int index)
{
	arr[index].val = nbr;
	arr[index].used = 1;
}

int	valid_arg(t_data *data, char *str)
{
	char	**split;
	int		i;

	if (!str || str[0] == 0)
		return (0);
	split = ft_split(str, data);
	init_data(data, data->nbrs);
	i = 0;
	while (i < data->nbrs)
	{
		if (is_valid_number(split[i]))
			add_list(data->arr_a, ft_atoi(split[i]), i);
		else
			return (free_all(data, split));
		i++;
	}
	free_split(split);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	i = 1;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (valid_arg(&data, argv[1]) != 1)
			return (write(2, "Error\n", 6));
	}
	else
	{
		init_data(&data, argc - 1);
		while (i < argc)
		{
			if (check_errors(argv[i], &data, i - 1) != 0)
				return (free_arrays(&data));
			add_list(data.arr_a, ft_atoi(argv[i]), i - 1);
			i++;
		}
	}
	get_min_max(&data);
	start_sorting(&data);
	free_arrays(&data);
}
