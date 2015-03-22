/*
** init.c for allum1 in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_allum1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Thu Feb 12 13:50:01 2015 Boulay Arnaud
** Last update Wed Feb 18 15:27:00 2015 Boulay Arnaud
*/

#include <stdlib.h>
#include "my.h"

t_flags		*init_struct(t_game *game, t_flags *flags, char **av)
{
  t_game	*tmp;
  int		total;

  total = 0;
  tmp = game->next;
  if ((flags = malloc(sizeof(t_flags))) == NULL)
    return (NULL);
  if (my_strcmp(av[2], "-p") == 1)
    flags->pvp = 1;
  else
    flags->pvp = 0;
  flags->turn = -1;
  flags->max_spaces = game->back->matches / 2;
  while (tmp != game)
    {
      total = total + tmp->matches;
      ++flags->row;
      tmp = tmp->next;
    }
  flags->matches = total;
  return (flags);
}

void		free_all(t_game *game, t_flags *flags)
{
  rm_list(game);
  free(flags);
}
