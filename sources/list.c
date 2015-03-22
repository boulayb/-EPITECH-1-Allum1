/*
** list.c for allum1 in /home/boulay_b/Work/cprogelem/Allum1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Tue Feb 10 17:55:21 2015 Boulay Arnaud
** Last update Wed Feb 11 13:47:37 2015 Boulay Arnaud
*/

#include <stdlib.h>
#include "my.h"

int		add_chain(t_game *game, int nb)
{
  t_game	*new_chain;

  if ((new_chain = malloc(sizeof(t_game))) == NULL)
    return (-1);
  new_chain->next = game;
  new_chain->back = game->back;
  new_chain->matches = nb;
  game->back->next = new_chain;
  game->back = new_chain;
  return (0);
}

void		rm_chain(t_game *chain)
{
  chain->back->next = chain->next;
  chain->next->back = chain->back;
  free(chain);
}

void		rm_list(t_game *game)
{
  t_game	*chain;
  t_game	*tmp;

  chain = game->next;
  while (chain != game)
    {
      tmp = chain->next;
      rm_chain(chain);
      chain = tmp;
    }
  free(game);
}

t_game		*create_game(int row)
{
  int		matches;
  t_game	*game;

  matches = 1;
  if  ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  game->next = game;
  game->back = game;
  game->matches = -1;
  while (row > 0)
    {
      if (add_chain(game, matches) == -1)
	return (NULL);
      row = row - 1;
      matches = matches + 2;
    }
  return (game);
}
