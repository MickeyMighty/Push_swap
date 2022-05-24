#include "../../include/swap.h"

void pa(t_data *data)
{
  int stock;

  stock = 0;
  if (data->size_b == 0)
    return ;
  stock = data->tab_b[0];
  rra(data);
  rb(data);
  data->size_a++;
  data->size_b--;
  data->tab_a[0] = stock;
}

void pb(t_data *data)
{
  int stock;

  stock = 0;
  if (data->size_a == 0)
  return ;
  stock = data->tab_a[0];
  rrb(data);
  ra(data);
  data->size_b++;
  data->size_a--;
  data->tab_b[0] = stock;
}
