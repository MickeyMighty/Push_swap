/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 23:33:54 by loamar            #+#    #+#             */
/*   Updated: 2022/05/31 16:58:14 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

static void	print_operation_three(t_data *data, int action)
{
	if (action == RRA)
	{
		rra(data);
		ft_putstr_fd("rra\n", 1);
	}
	else if (action == RRB)
	{
		rrb(data);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (action == RRR)
	{
		rrr(data);
		ft_putstr_fd("rrr\n", 1);
	}
}

static void	print_operation_two(t_data *data, int action)
{
	if (action == PB)
	{
		pb(data);
		ft_putstr_fd("pb\n", 1);
	}
	else if (action == RA)
	{
		ra(data);
		ft_putstr_fd("ra\n", 1);
	}
	else if (action == RB)
	{
		rb(data);
		ft_putstr_fd("rb\n", 1);
	}
	else if (action == RR)
	{
		rr(data);
		ft_putstr_fd("rr\n", 1);
	}
	else
		print_operation_three(data, action);
}

void	print_operation(t_data *data, int action)
{
	if (action == SA)
	{
		sa(data);
		ft_putstr_fd("sa\n", 1);
	}
	else if (action == SB)
	{
		sb(data);
		ft_putstr_fd("sb\n", 1);
	}
	else if (action == SS)
	{
		ss(data);
		ft_putstr_fd("ss\n", 1);
	}
	else if (action == PA)
	{
		pa(data);
		ft_putstr_fd("pa\n", 1);
	}
	else
		print_operation_two(data, action);
}
