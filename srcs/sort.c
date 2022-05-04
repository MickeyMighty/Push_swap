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

int   sort_big(t_data *data)
{
  int mediane;
  int pos;

  pos = 0;
  mediane = 0;
  if (data->size_a % 2 == 0)
    mediane = data_size_a / 2;
  else
    mediane = (data_size_a / 2) + 1;
  // while (data->size_a > 3)
  //   print_operation(PB);
  

}
