#include "../../include/swap.h"

void rra(t_data *data)
{
  int pos;

  pos = data->size_a;
  if (data->size_a <= 1)
  return ;
  while (pos > 0)
  {
    ft_swap(&data->tab_a[pos], &data->tab_a[pos - 1]);
    pos--;
  }
}

void rrb(t_data *data)
{
  int pos;

  pos = data->size_b;
  if (data->size_b <= 1)
  return ;
  while (pos > 0)
  {
    ft_swap(&data->tab_b[pos], &data->tab_b[pos - 1]);
    pos--;
  }
}

void rrr(t_data *data)
{
  rra(data);
  rrb(data);
}
