/*
** check.c for allum1 in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_allum1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Fri Feb 20 02:21:40 2015 Boulay Arnaud
** Last update Fri Feb 20 13:00:04 2015 Boulay Arnaud
*/

#include "my.h"

int		check_victory(t_game *game)
{
  t_game	*tmp;

  tmp = game->next;
  while (tmp != game)
    if (tmp->matches != 0)
      return (0);
    else
      tmp = tmp->next;
  return (1);
}

t_game		*find_bigger(t_game *game)
{
  int		bigger;
  t_game	*tmp;

  bigger = 0;
  tmp = game->next;
  while (tmp != game)
    {
      tmp = tmp->next;
      if (tmp->matches > bigger)
	bigger = tmp->matches;
    }
  tmp = game->next;
  while (tmp->matches != bigger)
    tmp = tmp->next;
  return (tmp);
}

int		check_final(t_game *game)
{
  int		filled;
  t_game	*tmp;

  filled = 0;
  tmp = game->next;
  while (tmp != game)
    {
      if (tmp->matches != 0)
	++filled;
      tmp = tmp->next;
    }
  if (filled < 3)
    {
      tmp = find_bigger(game);
      if (tmp->matches != 1 && filled == 1)
	tmp->matches = 1;
      else
	tmp->matches = 0;
      return (1);
    }
  return (0);
}
