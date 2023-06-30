/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:34:00 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/30 15:47:36 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*void    set_box(t_array *arr, int index, int box_nbr, int empty_box)
{
    arr[index].empty_box = empty_box;
    arr[index].box = box_nbr;
    if (empty_box == 0)
        printf("\nVal: %d, Box: %d", arr[index].val, arr[index].box);
}*/

int     get_nbr_digit(int val, int digit)
{
    int i;

    // if (val < 0)
    //     val = -val;
    i = 0;
    while (++i < digit)
        val /= 10;
    return (val % 10);
}

/*void    set_boxes(t_data *data, int digit)
{
    int index;
    int nbr;
    int n;
    //int extracted_number;

    //pour les unites, puis dizaines, centaines...
    //extraire les chiffres et mettre une box pour les nombres concernes

    // faire de -9 a 9
    n = -9;
    while (n < 10)
    {
        index = 0;
        while (index < data->total)
        {
            if (get_digits(data->arr_a[index].val) >= digit) // on peut mettre ce nombre dans une box
            {
                //printf("\n1. nbr: %d -> %d / digit: %d\n", data->arr_a[index].val, nbr, digit);
                nbr = get_nbr_digit(data->arr_a[index].val, digit);
                if (nbr == n)
                    set_box(data->arr_a, index, nbr, FILL);
                else
                    set_box(data->arr_a, index, nbr, EMPTY);
                //printf("\n2. nbr: %d -> %d / digit: %d\n", data->arr_a[index].val, data->arr_a[index].box, digit);
            }
            else
                set_box(data->arr_a, index, nbr, EMPTY);
            index++;
        }
        n++;
    }


    // index = 0;
    // while (index < data->total)
    // {
    //     if (get_digits(data->arr_a[index].val) >= digit) // on peut mettre ce nombre dans une box
    //     {
    //         //printf("\n1. nbr: %d -> %d / digit: %d\n", data->arr_a[index].val, nbr, digit);
    //         nbr = get_nbr_digit(data->arr_a[index].val, digit);
    //         set_box(data->arr_a, index, nbr, FILL);
    //         //printf("\n2. nbr: %d -> %d / digit: %d\n", data->arr_a[index].val, data->arr_a[index].box, digit);
    //     }
    //     else
    //         set_box(data->arr_a, index, nbr, EMPTY);
    //     index++;
    // }
}*/

/*void    check_box(t_array *arr, int box)
{

}*/

/*void    push_boxes(t_data *data)
{
    int n;
    int i;

    n = -9;
    while (n < 10)
    {
        i = 0;
        while (i < data->total)
        {
            //printf("\nempty: %d, box: %d, val: %d\n", data->arr_a[i].empty_box, data->arr_a[i].box, data->arr_a[i].val);
            if (data->arr_a[i].empty_box == 0 && data->arr_a[i].box == n && data->arr_a[i].val < 0)
            {
                push_list(data->arr_b, data->arr_a, 0, data->total);
	            display_lists(data);
            }
            else
            {
                rotate_list(data->arr_a, 0, data->total);
            }
	        //display_lists(data);
            i++;
        }
        n++;
    }
    // on va faire une boucle de -9 a 9
    // verifier les nombres negatifs ? 
    // genre faire de 9 a 1 pour le negatif, puis de 0 a 9 pour le positif
}*/

int get_arr_size(t_data *data)
{
    int i;

    i = 0;
    if (!data->arr_b[0].used)
        return (data->total);
    while (data->arr_a[i].used)
        i++;
    return (i);
}

int get_lower_number_index(t_data *data)
{
    int i;
    int index;
    int max_size;

    i = 0;
    index = 0;
    data->min_value = data->arr_a[0].val;
    max_size = get_arr_size(data);
    while (i < max_size && data->arr_a[i].used)
    {
        if (data->arr_a[i].val < data->min_value)
        {
            data->min_value = data->arr_a[i].val;
            index = i;
        }
        i++;
    }
    //printf("\nlower index: %d\n", index);
    return (index);
}

void    fast_sort(t_data *data)
{
    int lower_index;
    
    while (data->arr_a[0].used)
    {
        lower_index = get_lower_number_index(data);
        if (lower_index == 0)
            push_list(data->arr_b, data->arr_a, 1, data);
        else if (lower_index <= get_arr_size(data) - lower_index)
        {
            while (data->arr_a[0].val != data->min_value)
            {
                rotate_list(data->arr_a, 0, data);
                //display_lists(data);
                //printf("\nFirst value: %d, min value: %d\n", data->arr_a[0].val, data->min_value);
            }
            push_list(data->arr_b, data->arr_a, 1, data);
        }
        else if (lower_index > get_arr_size(data) - lower_index)
        {
            while (data->arr_a[0].val != data->min_value)
            {
                rev_rotate_list(data->arr_a, 0, data);
                //display_lists(data);
                //printf("\nFirst value: %d, min value: %d\n", data->arr_a[0].val, data->min_value);
            }
            push_list(data->arr_b, data->arr_a, 1, data);
        }
        //display_lists(data);
    }
}

void    push_back(t_data *data)
{
    int i;

    i = 0;
    while (i < data->total)
    {
        push_list(data->arr_a, data->arr_b, 0, data);
        i++;
    }
}

void    sort_big(t_data *data)
{
    fast_sort(data);
    push_back(data);
    // int i;

    // i = 1;
    // while (i <= data->max_digits)
    // {
    //     set_boxes(data, i);
    //     //printf("\n0. nbr: %d box: %d\n", data->arr_a[0].val, data->arr_a[0].box);
    //     push_boxes(data);
    //     i++;
    // }
/*

    

        List a:           List b:
    ---------------------------------
    |       3       |       -       |
    |      18       |       -       |
    |       4       |       -       |
    |      12       |       -       |
    |       2       |       -       |
    ---------------------------------

    on va mettre chaque nombre dans des box correspondant aux chiffres 
    (unites, puis dizaines, centaines...)

        List a:           List b:
    ---------------------------------
    |       -       |      12       |
    |       -       |       2       |
    |       -       |       3       |
    |       -       |       4       |
    |       -       |      18       |
    ---------------------------------

    on les push dans l'arr_b dans l'ordre et de nouveau dans l'arr_a (de -9 a 9)

          List a:           List b:
    ---------------------------------
    |      12       |       -       |
    |       2       |       -       |
    |       3       |       -       |
    |       4       |       -       |
    |      18       |       -       |
    ---------------------------------

    on recommence pour les dizaines

          List a:           List b:
    ---------------------------------
    |       2       |      12       |
    |       3       |      18       |
    |       4       |       -       |
    |       -       |       -       |
    |       -       |       -       |
    ---------------------------------

    on les push et on fait un rotate

          List a:           List b:
    ---------------------------------
    |      12       |      18       |
    |       2       |       -       |
    |       3       |       -       |
    |       4       |       -       |
    |       -       |       -       |
    ---------------------------------

          List a:           List b:
    ---------------------------------
    |       2       |      18       |
    |       3       |       -       |
    |       4       |       -       |
    |      12       |       -       |
    |       -       |       -       |
    ---------------------------------

    on push le deuxieme et on fait un rotate aussi

          List a:           List b:
    ---------------------------------
    |      18       |       -       |
    |       2       |       -       |
    |       3       |       -       |
    |       4       |       -       |
    |      12       |       -       |
    ---------------------------------

          List a:           List b:
    ---------------------------------
    |       2       |       -       |
    |       3       |       -       |
    |       4       |       -       |
    |      12       |       -       |
    |      18       |       -       |
    ---------------------------------

*/
}
