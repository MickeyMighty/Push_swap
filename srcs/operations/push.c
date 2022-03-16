
static int *sort_tab(int *tab, int stock, int size_max, int mode)
{
  int pos;

  if (mode == SWAP_ALL)
    pos = 0;
  else if (mode == SWAPP_LESS_FIRST)
    pos = 1;
  while (pos < size_max)
  {
    ft_swap(tab[pos], stock)
    stock = tab[pos + 1];
    pos++;
  }
  return (tab);
}

void pa(t_data *data)
{
  int stock;

  stock = 0;
  if (data->size_b = 0)
    return ;
  stock = data->tab_a[0];
  data->tab_a[0] = data->tab_b[0];
  data->size_a++;
  data->size_b--;
  if (data->size_a > 1)
    data->tab_a = sort_tab(data->tab_a, stock, data->size_a, SWAPP_LESS_FIRST);
  if (data->size_b > 0)
    data->tab_b = sort_tab(data->tab_b, data->tab_b[0], data->size_b, SWAPP_ALL);
}

void pb(t_data *data)
{
  int stock;

  stock = 0;
  if (data->size_a = 0)
    return ;
  stock = data->tab_b[0];
  data->tab_b[0] = data->tab_a[0];
  data->size_b++;
  data->size_a
  if (data->size_b > 1)
    data->tab_b = sort_tab(data->tab_b, stock, data->size_b, SWAPP_LESS_FIRST);
  if (data->size_a > 0)
    data->tab_a = sort_tab(data->tab_a, data->tab_a[0], data->size_a, SWAPP_ALL);
}
