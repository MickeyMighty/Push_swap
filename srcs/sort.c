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


//
// static int  search_max_number(t_data *data)
// {
//   int pos;
//   int i;
//   int stock;
//
//
//   pos = 0;
//   i = 1;
//   stock = data->tab_a[0];
//   while (pos <= data->size_a)
//   {
//     if (data->tab_a[pos] > stock)
//       stock = data->tab_a[pos];
//     pos++;
//   }
//   pos = 0;
//   while (data->tab_a[pos] != stock)
//   {
//     pos++;
//     i++;
//   }
//   return (i);
// }
//
// static void max_sort_top(t_data *data, int max)
// {
//   if (max <= data->size_b / 2)
//   {
//     while (max && max != 1)
//     {
//       print_operation(data, RB);
//       max--;
//     }
//   }
//   else if (max != 1)
//   {
//     while (max <= data->size_b)
//     {
//       // print_tab(data);
//       print_operation(data, RRB);
//       // print_tab(data);
//       max++;
//     }
//   }
// }
//
// void sort_top(t_data *data)
// {
//   // int pos;
//   int max;
//
//   max = 0;
//   // pos = 0;
//   // printf("|sort_top|\n");
//   while (data->size_b)
//   {
//     // print_tab(data);
//     max = search_max_number(data);
//     max_sort_top(data, max);
//     print_operation(data, PA);
//   }
// }
