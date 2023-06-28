/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:00:38 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/28 17:37:27 by cpothin          ###   ########.fr       */
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

void	add_list(t_array *arr, int nbr, int index)
{
	arr[index].val = nbr;
	arr[index].used = 1;
	// t_lst	*n;

	// while (lst->next != NULL)
	// 	lst = lst->next;
	// n = (t_lst *)malloc(sizeof(t_lst));
	// if (!n)
	// 	return ;
	// n->data = nbr;
	// n->next = NULL;
	// lst->next = n;
}

int	main(int argc, char *argv[])
{
/*
	- verifier les arguments du style "2 5", c'est un argument mais il faut faire un split pour le transformer apparemment
	- ft_strtol ne fonctionne pas correctement. Verifier pourquoi...
	- crash sur le lsts[1] ? segfault... voir avec valgrind
*/
	t_data	data;
	// t_lst	*lsts[2];
	int		i;

	i = 1;
	if (argc == 1)
		return (0);
	else if (argc == 2) // verifier ici si on peut faire un split en nombres
		return (write(2, "Error!\n\tYou have to put at least 2 numbers\n", 43));
	init_data(&data, argc - 1);
	while (i < argc)
	{
		if (check_errors(argv[i], &data) != 0)
			return (0);
		add_list(data.arr_a, ft_atoi(argv[i]), i - 1);
		i++;
	}
	display_lists(&data);
	//start_sorting(&data);
	//swap_list(&lsts[0]);
	push_list(data.arr_b, data.arr_a, 0);
	//rotate_list(&lsts[0]);
	//rev_rotate_list(&lsts[0]);
	display_lists(&data);
	free_all(&data);
}
