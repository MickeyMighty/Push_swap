int sort_tab(t_data *data)
{
  ;
}

int fill_tab(t_data *data, char **argv)
{
  int pos;

  pos = 0;
  data->tab_a = malloc(sizeof(int) * data->size_tab);
  if (!data->tab_a)
    return (ERROR);
  data->tab_b = malloc(sizeof(int) * data->size_tab);
  if (!data->tab_b)
    return (ERROR);
  while (pos <= data->size_tab)
  {
    data->tab_a[pos] = ft_atoi(argv[pos + 1]);
    pos++;
  }
}
