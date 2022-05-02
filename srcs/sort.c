int   sort_two_three(t_data *data)
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
