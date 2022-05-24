#include "../../include/swap.h"

void ra(t_data *data)
{
    int   pos;
    int   stock;

    stock = 0;
    pos = 0;
    if (data->size_a <= 1)
        return ;
    stock = data->tab_a[pos];
    while (pos < data->size_a)
    {
        ft_swap(&data->tab_a[pos], &data->tab_a[pos + 1]);
        pos++;
    }
    data->tab_a[data->size_a - 1] = stock;
}

void rb(t_data *data)
{
    int pos;
    int stock;

    stock = 0;
    pos = 0;
    if (data->size_b <= 1)
        return ;
    stock = data->tab_b[pos];
    while (pos < data->size_b)
    {
        ft_swap(&data->tab_b[pos], &data->tab_b[pos + 1]);
        pos++;
    }
    data->tab_b[data->size_b - 1] = stock;
}

void rr(t_data *data)
{
  ra(data);
  rb(data);
}
