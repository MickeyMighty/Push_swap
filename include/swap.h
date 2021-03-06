/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:04:59 by loamar            #+#    #+#             */
/*   Updated: 2022/06/09 12:12:08 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define SUCCESS 0
# define ERROR -1
# define SWAP_ALL -1
# define SWAPP_LESS_FIRST 0
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct data
{
	int	*tab_a;
	int	*tab_b;
	int	**lair_tab;
	int	size_a;
	int	size_b;
	int	size_lair;
	int	free_lair_tab;
}							t_data;

/*
 ** MAIN
 */

int		find_min_nbr(t_data *data);
int		fill_tab(t_data *data, char **argv);
void	free_data(t_data *data, int flag);
void	print_tab(t_data *data); // pour afficher test

/*
 ** TOOLS
 */

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(long int n);
void	ft_putchar_fd(char c, int fd);
long		ft_atoi(const char *str);
int		ft_isdigit(int c);

/*
 ** OPERATIONS/PUSH
 */

void	pa(t_data *data);
void	pb(t_data *data);

/*
 ** OPERATIONS/ROTATE_REVERSE
 */

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

/*
 ** OPERATIONS/ROTATE
 */

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

/*
 ** OPERATIONS/SWAP
 */

void	ft_swap(int *a, int *b);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

/*
 ** PRINT
 */

void	print_operation(t_data *data, int action);

/*
 ** HANDLER_LAIRTAB
 */

int		create_lairtab(t_data *data);
int		find_index(t_data *data);

/*
 ** CHECK
 */

int		check_arg(int argc, char **argv);
int		check_double(t_data *data);
int		check_is_good(t_data *data);

/*
 ** SORT
 */
int		sort_tab(t_data *data);
int		sort_big(t_data *data, int size);
int		sort_two_three(t_data *data);

#endif
