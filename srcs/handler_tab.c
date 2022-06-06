/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:45:45 by loamar            #+#    #+#             */
/*   Updated: 2022/05/31 16:49:59 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

int	check_is_good(t_data *data)
{
	int	pos;
	int	pos2;

	pos = 0;
	pos2 = 1;
	while (pos2 < data->size_a)
	{
		if (data->tab_a[pos] > data->tab_a[pos2])
			return (ERROR);
		pos++;
		pos2++;
	}
	return (SUCCESS);
}

static int	find_index(t_data *data)
{
	int	find;
	int	target;

	find = 0;
	target = 0;
	find = data->tab_a[0];
	while (target < data->size_lair)
	{
		if (data->lair_tab[0][target] == find)
			break ;
		else
			target++;
	}
	return (data->lair_tab[1][target]);
}

static int	sort_big(t_data *data, int size)
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
		sort_big(data, data->size_a);
		printf("-1-\n");
		free_data(data, 2);
		printf("-2-\n");
		return (SUCCESS);
	}
}

int	fill_tab(t_data *data, char **argv)
{
	int	pos;

	pos = 0;
	data->tab_a = malloc(sizeof(int) * data->size_a);
	if (!data->tab_a)
		return (ERROR);
	data->tab_b = malloc(sizeof(int) * data->size_b);
	if (!data->tab_b)
		return (ERROR);
	while (pos < data->size_a)
	{
		data->tab_a[pos] = ft_atoi(argv[pos + 1]);
		pos++;
	}
	data->free_lair_tab = 0;
	return (SUCCESS);
}
