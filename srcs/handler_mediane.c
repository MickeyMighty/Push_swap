#include "../include/swap.h"

static int  *sort_lair_tab(t_data *data, int *tab)
{
  long  tmp;
  int pos;

  tmp = 0;
  pos = 0;
  while (pos < data->size_a)
  {
    if (tab[pos] <= tab[pos + 1])
      pos++;
    else
    {
      tmp = tab[pos];
      tab[pos] = tab[pos + 1];
      tab[pos + 1] = tmp;
      pos = 0;
    }
  }
  return (tab);
}

static int  *handler_lair_tab(t_data *data, int *tab)
{
  int pos;

  pos = 0;
  tab = malloc(sizeof(int) * data->size_a);
  if (!tab)
    return (NULL);
  while (pos <= data->size_a)
  {
    tab[pos] = data->tab_a[pos];
    pos++;
  }
  // tab = sort_lair_tab(data, tab);
  return (tab);
}

int   get_mediane(t_data *data)
{
  int  pos;
  int  mediane;
  int  *lair_tab;

  lair_tab = NULL;
  lair_tab = handler_lair_tab(data, lair_tab);
  lair_tab = sort_lair_tab(data, lair_tab);
  pos = 0;
  mediane = 0;
  if (data->size_a >= 500)
    pos = data->size_a / 7;
  else
    pos = data->size_a / 5;
  mediane = lair_tab[pos];
  free(lair_tab);
  return (mediane);
}
