/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:58:35 by loamar            #+#    #+#             */
/*   Updated: 2022/05/31 17:02:46 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

int	sort_two_three(t_data *data)
{
	if (data->size_a == 2)
		print_operation(data, SA);
	else if (data->size_a == 3)
	{
		if (data->tab_a[0] > data->tab_a[1] && data->tab_a[0] > data->tab_a[2])
		{
			print_operation(data, RA);
			print_tab(data);
			if (check_is_good(data) == ERROR)
				print_operation(data, SA);
			print_tab(data);
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
	if (check_is_good(data) == SUCCESS)
	{
		free_data(data, 1);
		return (SUCCESS);
	}
	if (data->size_a <= 3)
	{
		sort_two_three(data);
		free_data(data, 1);
		return (SUCCESS);
	}
	else
	{
		if (create_lairtab(data) == ERROR)
			return (ERROR);
		printf("-1-\n");
		sort_big(data, data->size_a);
		free_data(data, 2);
		printf("-2-\n");
		return (SUCCESS);
	}
}
