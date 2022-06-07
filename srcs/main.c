/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:13:02 by loamar            #+#    #+#             */
/*   Updated: 2022/05/31 16:51:17 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

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

static	int	error_msg()
{
	ft_putstr_fd("Error", 2);
	ft_putchar_fd('\n', 2);
	return (ERROR);
}

void print_tab(t_data *data) // pour afficher test
{
	int pos;

	pos = 0;
	printf("===============\n");
	printf("|-tab A-|\n");
	while (pos < data->size_a)
	{
		printf("%d-[%d]\n", pos, data->tab_a[pos]);
		pos++;
	}
	pos = 0;
	printf("|-tab B-|\n");
	while (pos < data->size_b)
	{
		printf("%d-[%d]\n", pos, data->tab_b[pos]);
		pos++;
	}
	printf("===============\n");
}

void free_data(t_data *data, int flag)
{
	if (flag == 1 || flag == 2)
	{
		if (flag == 2)
		{
			printf("2\n");
			free(data->lair_tab[1]);
			printf("3\n");
			free(data->lair_tab[0]);
			printf("4\n");
			free(data->lair_tab);
			printf("5\n");
		}
		free(data->tab_a);
		printf("6\n");
		free(data->tab_b);
		printf("7\n");
	}
}
int		main(int argc, char **argv)
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
