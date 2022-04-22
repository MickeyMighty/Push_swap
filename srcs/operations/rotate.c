#include "../../include/swap.h"

void ra(t_data *data)
{
  int pos;

  pos = 0;
  if (data->size_a <= 1)
    return ;
  while (pos < data->size_a)
  {
    ft_swap(data->tab_a[pos], data->tab_a[pos + 1]);
    pos++;
  }
}

void rb(t_data *data)
{
  int pos;

  pos = 0;
  if (data->size_b <= 1)
  return ;
  while (pos < data->size_b)
  {
    ft_swap(data->tab_b[pos], data->tab_b[pos + 1]);
    pos++;
  }
}

void rr(t_data *data)
{
  ra(data);
  rb(data);
}
