#include "../include/swap.h"

int   sort_two_three(t_data *data)
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
    else if (data->tab_a[1] > data->tab_a[0] && data->tab_a[1] > data->tab_a[2])
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


static int  give_index(t_data *data, int pos)
{
  int index;
  int nbr;
  int cmp;

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

int  create_lairtab(t_data *data)
{
  int pos;

  pos = 0;
  data->lair_tab = malloc(sizeof(int *) * 2);
  if (!data->lair_tab)
    return (ERROR);
  data->lair_tab[0] = malloc(sizeof(int) * data->size_a);
  if (!data->lair_tab[0])
    return (ERROR);
  data->lair_tab[1] = malloc(sizeof(int) * data->size_a);
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
