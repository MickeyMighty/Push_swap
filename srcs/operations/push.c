#include "../../include/swap.h"

void pa(t_data *data)
{
  int stock;

  stock = 0;
  if (data->size_b == 0)
    return ;
  stock = data->tab_b[0];
  data->size_a++;
  rb(data);
  data->size_b--;
  rra(data);
  data->tab_a[0] = stock;
}

void pb(t_data *data)
{
  int stock;

  stock = 0;
  if (data->size_a == 0)
    return ;
  stock = data->tab_a[0];
  data->size_b++;
  ra(data);
  data->size_a--;
  rrb(data);
  data->tab_b[0] = stock;
}
