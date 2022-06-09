/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:13:02 by loamar            #+#    #+#             */
/*   Updated: 2022/06/09 12:19:16 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

int	find_min_nbr(t_data *data)
{
	int	pos;
	int	min;
	int	nbr;

	pos = 0;
	nbr = data->tab_a[pos];
	min = pos;
	pos++;
	while (pos < data->size_a)
	{
		if (data->tab_a[pos] < nbr)
		{
			min = pos;
			nbr = data->tab_a[pos];
		}
		pos++;
	}
	return (min);
}

int	fill_tab(t_data *data, char **argv)
{
	int	pos;
	long check;

	pos = 0;
	data->tab_a = malloc(sizeof(int) * data->size_a);
	if (!data->tab_a)
		return (ERROR);
	data->tab_b = malloc(sizeof(int) * data->size_a);
	if (!data->tab_b)
		return (ERROR);
	while (pos < data->size_a)
	{
		check = (long)ft_atoi(argv[pos + 1]);
		if (check > 2147483647 || check < (-2147483647 - 1))
			return (ERROR);
		else
			data->tab_a[pos] = (int)check;
		// data->tab_a[pos] = ft_atoi(argv[pos + 1]);
		pos++;
	}
	data->free_lair_tab = 0;
	return (SUCCESS);
}

static int	error_msg(void)
{
	ft_putstr_fd("Error", 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}

void	free_data(t_data *data, int flag)
{
	if (flag == 1 || flag == 2)
	{
		if (flag == 2)
		{
			free(data->lair_tab[1]);
			free(data->lair_tab[0]);
			free(data->lair_tab);
		}
		free(data->tab_a);
		free(data->tab_b);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	if (check_arg(argc, argv) == ERROR)
		return (error_msg());
	data.size_a = argc - 1;
	data.size_b = 0;
	data.size_lair = argc - 1;
	if (fill_tab(&data, argv) == ERROR)
		return (error_msg());
	if (check_double(&data) == ERROR)
	{
		free_data(&data, 1);
		return (error_msg());
	}
	sort_tab(&data);
}
