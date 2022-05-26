#include "../include/swap.h"

int check_is_good(t_data *data)
{
  int pos;
  int pos2;

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

static int  give_index(t_data *data)
{
  int index;
  int pos;
  int nbr;

  nbr = 0;
  pos = 0;
  index = 0;
  nbr = data->tab_a[pos];
  pos++;
  while (pos < data->size_a)
  {
    if (nbr > data->tab_a[pos])
      index++;
    pos++;
  }
  printf("index = %d\n", index);
  // print_tab(data);
  return (index);
}

int   sort_big(t_data *data)
{
  int i;
  int j;
  int stock;
  int bits;

  bits = 0;
  while ((data->size_a) >> bits != 0)
    bits++;
  i = 0;
  while (i <= bits)
  {
    j = 0;
    while (j <= data->size_a)
    {
      stock = give_index(data);
      if (((stock >> i) & 1) == 1)
      {
        print_operation(data, RA);
        print_tab(data);
      }
      else
      {
        print_operation(data, PB);
        print_tab(data);
      }
      j++;
    }
    while (data->size_b)
    {
      print_operation(data, PA);
      print_tab(data);
    }
    i++;
  }
  return (SUCCESS);
  // int mediane;
  // int pos;
  // // int size;
  //
  // pos = 0;
  // // size = 0;
  // mediane = 0;
  // while (data->size_a) // petit ?
  // {
  //   mediane = get_mediane(data);
  //   pos = data->size_a;
  //   // printf("mediane = %d\n", mediane);
  //   // printf("pos = %d\n",pos);
  //   // exit(0);
  //   while (pos)
  //   {
  //     if (data->tab_a[0] <= mediane || data->size_a == 1)
  //       print_operation(data, PB);
  //     else
  //       print_operation(data, RA);
  //     pos--;
  //   }
  //   // size++;
  // }
  // print_tab(data);
  // sort_top(data);
  // return (SUCCESS);
}

int sort_tab(t_data *data)
{
  if (check_is_good(data) == SUCCESS)
    return (SUCCESS);
  if (data->size_a <= 3)
    return (sort_two_three(data));
  else
    return (sort_big(data));
}

int fill_tab(t_data *data, char **argv)
{
  int pos;

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
  return (SUCCESS);
}
