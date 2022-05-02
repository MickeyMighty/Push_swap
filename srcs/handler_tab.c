#include "../include/swap.h"

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

int sort_tab(t_data *data)
{
  if (check_is_good(data) == SUCCESS)
    return (SUCCESS);
  if (data->size_a <= 3)
    return (sort_two_three(data));
  if (data->size_ <= 4)
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
