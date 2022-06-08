/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:58:35 by loamar            #+#    #+#             */
/*   Updated: 2022/06/09 00:33:06 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

static int	while_sizethree(int rotate, t_data *data)
{
	while (data->size_a > 3)
	{
		rotate = find_min_nbr(data);
		if (rotate == 1 || (rotate == 2 && data->size_a == 5))
		{
			while (rotate > 0)
			{
				print_operation(data, RA);
				if (check_is_good(data) == SUCCESS)
					return (ERROR);
				rotate--;
			}
		}
		else if (rotate == 2 || rotate == 3 || rotate == 4)
		{
			while (rotate < data->size_a)
			{
				print_operation(data, RRA);
				if (check_is_good(data) == SUCCESS)
					return (ERROR);
				rotate++;
			}
		}
		print_operation(data, PB);
	}
	return (SUCCESS);
}

int	sort_four_five(t_data *data)
{
	int	rotate;

	rotate = 0;
	if (while_sizethree(rotate, data) == ERROR)
		return (SUCCESS);
	sort_two_three(data);
	while (data->size_b > 0)
		print_operation(data, PA);
	return (SUCCESS);
}

int	sort_two_three(t_data *data)
{
	if (data->size_a == 2)
		print_operation(data, SA);
	else if (data->size_a == 3)
	{
		if (data->tab_a[0] > data->tab_a[1] && data->tab_a[0] > data->tab_a[2])
		{
			print_operation(data, RA);
			if (check_is_good(data) == ERROR)
				print_operation(data, SA);
		}
		else if (data->tab_a[1] > data->tab_a[0]
			&& data->tab_a[1] > data->tab_a[2])
		{
			print_operation(data, RRA);
			if (check_is_good(data) == ERROR)
				print_operation(data, SA);
		}
		else
			print_operation(data, SA);
	}
	return (SUCCESS);
}

int	sort_big(t_data *data, int size)
{
	int	i;
	int	j;
	int	stock;
	int	bits;

	bits = 0;
	while ((data->size_a - 1) >> bits != 0)
		bits++;
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j++ < size)
		{
			stock = find_index(data);
			if (((stock >> i) & 1) == 1)
				print_operation(data, RA);
			else
				print_operation(data, PB);
		}
		while (data->size_b)
			print_operation(data, PA);
		i++;
	}
	return (SUCCESS);
}

int	sort_tab(t_data *data)
{
	if (check_is_good(data) == SUCCESS || data->size_a == 1)
		free_data(data, 1);
	else if (data->size_a <= 5)
	{
		if (data->size_a <= 3)
			sort_two_three(data);
		else if (data->size_a == 4 || data->size_a == 5)
			sort_four_five(data);
		free_data(data, 1);
	}
	else
	{
		if (create_lairtab(data) == ERROR)
			return (ERROR);
		sort_big(data, data->size_a);
		free_data(data, 2);
	}
	return (SUCCESS);
}
