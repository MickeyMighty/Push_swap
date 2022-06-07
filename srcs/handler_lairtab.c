#include "../include/swap.h"

int	find_index(t_data *data)
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

static int	give_index(t_data *data, int pos)
{
	int	index;
	int	nbr;
	int	cmp;

	nbr = 0;
	index = 0;
	nbr = data->lair_tab[0][pos];
	cmp = pos;
	pos++;
	if (pos == data->size_a)
		pos = 0;
	while (pos != cmp)
	{
		if (nbr > data->lair_tab[0][pos])
			index++;
		pos++;
		if (pos == data->size_a)
			pos = 0;
	}
	return (index);
}

int	create_lairtab(t_data *data)
{
	int	pos;

	pos = 0;
	data->lair_tab = malloc(sizeof(int *) * 2);
	if (!data->lair_tab)
		return (ERROR);
	data->lair_tab[0] = malloc(sizeof(int) * (data->size_a));
	if (!data->lair_tab[0])
		return (ERROR);
	data->lair_tab[1] = malloc(sizeof(int) * (data->size_a));
	if (!data->lair_tab[1])
		return (ERROR);
	while (pos < data->size_a)
	{
		data->lair_tab[0][pos] = data->tab_a[pos];
		pos++;
	}
	pos = 0;
	while (pos < data->size_a)
	{
		data->lair_tab[1][pos] = give_index(data, pos);
		pos++;
	}
	return (SUCCESS);
}
