/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:00:38 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/30 14:19:02 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*void	check_argument(t_lst *list1, t_lst *list2, char *arg)
{
	if (ft_strcmp(arg, "sa") == 0)
		swap_list(list1, 0);
	else if (ft_strcmp(arg, "sb") == 0)
		swap_list(list2, 1);
	else if (ft_strcmp(arg, "ss") == 0)
	{
		swap_list(list1, -1);
		swap_list(list2, 2);
	}
	else if (ft_strcmp(arg, "pa") == 0)
		push_list(&list1, &list2, 0);
	else if (ft_strcmp(arg, "pb") == 0)
		push_list(&list2, &list1, 1);
	else if (ft_strcmp(arg, "ra") == 0)
		rotate_list(list1, 0);
	else if (ft_strcmp(arg, "rb") == 0)
		rotate_list(list2, 1);
	else if (ft_strcmp(arg, "rr") == 0)
	{
		rotate_list(list1, -1);
		rotate_list(list2, 2);
	}
	else if (ft_strcmp(arg, "rra") == 0)
		rev_rotate_list(&list1, 0);
	else if (ft_strcmp(arg, "rrb") == 0)
		rev_rotate_list(&list2, 1);
	else if (ft_strcmp(arg, "rrr") == 0)
	{
		rev_rotate_list(&list1, -1);
		rev_rotate_list(&list2, 2);
	}
	else
		write(2, "Error\n", 6);
}*/

void	free_split(char **split)
{
	int	i;
	
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

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
	int	i;

	split = ft_split(str, data);
	init_data(data, data->nbrs);
	i = 0;
	while (i < data->nbrs)
	{
		if (is_valid_number(split[i]))
			add_list(data->arr_a, ft_atoi(split[i]), i);
		else
		{
			free_split(split);
			free_all(data);
			return (0);
		}
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
	else if (argc == 2) // verifier ici si on peut faire un split en nombres
	{
		if (valid_arg(&data, argv[1]) == 0)
			return (write(2, "Error!\n\tYou have to put at least 2 numbers\n", 43));
	}
	else
	{
		init_data(&data, argc - 1);
		while (i < argc)
		{
			if (check_errors(argv[i], &data) != 0)
				free_all(&data);
			add_list(data.arr_a, ft_atoi(argv[i]), i - 1);
			i++;
		}
	}
	get_min_max(&data);
	//display_lists(&data);
	start_sorting(&data);
	//swap_list(data.arr_a, 0);
	//push_list(data.arr_b, data.arr_a, 0, data.total);
	//rotate_list(data.arr_a, 0, data.total);
	//rev_rotate_list(data.arr_a, 0, data.total);
	//display_lists(&data);
	//printf("\nCalculations: %d\n", data.calculations);
	free_all(&data);
}
