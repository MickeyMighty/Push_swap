#include "../include/swap.h"

int   sort_two_three(t_data *data)
{
  printf("sorting 2 and 3\n");
  if (data->size_a == 2)
    print_operation(data, SA);
  else if (data->size_a == 3)
  {
    if (data->tab_a[0] > data->tab_a[1] && data->tab_a[0] > data->tab_a[2])
    {
      print_operation(data, RA);
      if (check_is_good(data) == ERROR)
        print_operation(data, SA);
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

int   get_mediane(t_data *data)
{
  int  pos;
  int  mediane;

  pos = 0;
  mediane = 0;
  if (data->size_a >= 500)
    pos = data->size_a / 7;
  else
    pos = data->size_a / 5;
  mediane = data->tab_a[pos];
  return (mediane);
}

static int  search_max_number(t_data *data)
{
  int pos;
  int stock;


  pos = 0;
  stock = data->tab_a[pos];
  while (pos <= data->size_a)
  {
    if (data->tab_a[pos] > stock)
      stock = data->tab_a[pos];
    pos++;
  }
  return (pos);
}

static void max_sort_top(t_data *data, int max)
{
  if (max <= data->size_b / 2)
  {
    while (max && max != 1)
    {
      print_operation(data, RB);
      max--;
    }
  }
  else if (max != 1)
  {
    while (max <= data->size_a)
    {
      print_operation(data, RRB);
      max++;
    }
  }
}

void sort_top(t_data *data)
{
  int pos;
  int max;

  max = 0;
  pos = 0;
  while (pos < data->size_b)
  {
    max = search_max_number(data);
    max_sort_top(data, max);
    print_operation(data, PA);
    pos++;
  }
}
