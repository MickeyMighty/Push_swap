/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:55:26 by loamar            #+#    #+#             */
/*   Updated: 2022/06/09 00:35:59 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/swap.h"

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	sa(t_data *data)
{
	if (data->size_a < 2)
		return ;
	ft_swap(&data->tab_a[0], &data->tab_a[1]);
	return ;
}

void	sb(t_data *data)
{
	if (data->size_b < 2)
		return ;
	ft_swap(&data->tab_b[0], &data->tab_b[1]);
	return ;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
