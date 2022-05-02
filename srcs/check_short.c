int check_is_good(t_data *data)
{
  int pos;
  int pos2;

  pos = 0;
  pos2 = 1;
  while (pos2 < data->size_a)
  {
    if (data->tab_a[pos] > data->tab_a[pos2])
      return (ERROR);
    pos++;
    pos2++;
  }
  return (SUCCESS);
}
