#include "../../include/swap.h"

void pa(t_data *data)
{
  int stock;

  stock = 0;
  if (data->size_b == 0)
    return ;
  data->size_a++;
  data->size_b--;
  stock = data->tab_b[0];
  rra(data);
  rb(data);
  data->tab_a[0] = stock;
}

void pb(t_data *data)
{
  int stock;

  stock = 0;
  if (data->size_a == 0)
  return ;
  data->size_b++;
  data->size_a--;
  stock = data->tab_a[0];
  rrb(data);
  ra(data);
  data->tab_b[0] = stock;
}
