++++f+++++++-+int   sort_two_three(t_data *data)
{
  if (data->size_a == 2
    print_operation(SA
  else if (data->size_a == 3)
  {
    if (data->tab_a[0] > data->tab_a[1] && data->tab_a[0] > data->tab_a[2])
    {
      print_operation(RA);
      if (check_is_good(data) == ERROR)
        print_operation(SA);
    }
  }
  else if (data->tab_a[1] > data->tab_a[0] && data->tab_a[1] > data->tab_a[2])
  {
    print_operation(RRA);
    if (check_is_good(data) == ERROR)
      print_operation(SA);
  }
  else
    print_operation(SA);
  return (SUCCESS);
}

static int   get_mediane(t_data *data)
{
  int  pos;
  int  mediane;

  pos = 0;
  mediane = 0;
  if (data->size_a >= 500)
    pos = data->size_a / 7;
  else
    pos = size / 5;
  mediane = data->tab_a[pos];
  return (mediane);
}

int   sort_big(t_data *data)
{
  int mediane;
  int pos;

  pos = 0;
  mediane = 0;
  while (pos <= data->size_a)
  {
    if (data->tab_a[pos] <= mediane)
      print_operation(PB);
    else
      print_operation(RA);
    pos++;
  }
  // while (data->size_a > 3)
  //   print_operation(PB);
}
