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

int   sort_big(t_data *data)
{
  int i;
  int j;
  int stock;
  int bits;

  bits = 0;
  while ((data->size_a - 1) >> bits != 0)
    bits++;
  i = 0;
  while (i < bits)
  {
    j = 0;
    while (j <= data->size_a)
    {
      stock = data->tab_a[0];
      if (((stock >> i) & 1) == 1)
        print_operation(data, RA);
      else
        print_operation(data, PB);
      j++;
    }
    while (data->size_b)
      print_operation(data, PA);
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
