/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:02:02 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/28 17:37:10 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>

typedef struct s_lst	t_lst;

// struct	s_lst
// {
// 	int		data;
// 	t_lst	*next;
// };

typedef struct	s_array
{
	int	val;
	int	used;
}				t_array;

typedef struct s_data
{
	t_array	*arr_a;
	t_array	*arr_b;
	int	total;
	int	min_value;
	int	max_value;
	int	calculations;
	int	is_sorted;
}		t_data;

void	display_lists(t_data *data);
void	swap_list(t_array *arr, int n);
void	push_list(t_array *arr1, t_array *arr2, int n);
void	rotate_list(t_array *arr, int n, int max);
void	rev_rotate_list(t_array *arr, int n, int max);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	free_all(t_data *data);
void	get_min_max(t_data *data);
void	init_data(t_data *data, int nb);
void	start_sorting(t_data *data);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		check_errors(char *str, t_data *data);
int		check_sorted(t_data *data);
long	ft_strtol(const char *nptr, char **endptr);

#endif