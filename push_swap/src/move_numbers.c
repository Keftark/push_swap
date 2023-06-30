/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 08:17:48 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/30 11:26:17 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    move_number(t_array *arr_from, t_array *arr_to, int from, int to)
{
    // arr_to[to].empty_box = arr_from[from].empty_box;
    // arr_to[to].box = arr_from[from].box;
    arr_to[to].val = arr_from[from].val;
    arr_to[to].used = 1;
}

void    empty_number(t_array *arr, int n)
{
    arr[n].used = 0;
    // arr[n].box = -10;
    // arr[n].empty_box = 1;
}

int     get_last_value(t_array *arr, int max)
{
    int i;

    i = max - 1;
    while (i > 0)
    {
        if (arr[i].used)
            return (arr[i].val);
        i--;
    }
    return (0);
}