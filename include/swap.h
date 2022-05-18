/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:04:59 by loamar            #+#    #+#             */
/*   Updated: 2022/04/22 13:02:37 by loamar           ###   ########.fr       */
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
  int *tab_a;
  int *tab_b;
  int size_a;
  int size_b;
  int pos_a;
  int pos_b;
}							t_data;


//  a supprimer, juste pour les test
void print_tab(t_data *data); // pour afficher test
/*
** TOOLS
*/

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(long int n);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);

/*
** OPERATIONS/PUSH
*/

void pa(t_data *data);
void pb(t_data *data);

/*
** OPERATIONS/ROTATE_REVERSE
*/

void rra(t_data *data);
void rrb(t_data *data);
void rrr(t_data *data);

/*
** OPERATIONS/ROTATE
*/

void ra(t_data *data);
void rb(t_data *data);
void rr(t_data *data);

/*
** OPERATIONS/SWAP
*/

void	ft_swap(int *a, int *b);
void sa(t_data *data);
void sb(t_data *data);
void ss(t_data *data);

/*
** PRINT
*/

void	print_operation(t_data *data, int action);

/*
** HANDLER_TAB
*/

int check_is_good(t_data *data);
int sort_big(t_data *data);
int sort_tab(t_data *data);
int fill_tab(t_data *data, char **argv);

/*
** SORT
*/

int   sort_two_three(t_data *data);
int   get_mediane(t_data *data);
void sort_top(t_data *data);

# endif
