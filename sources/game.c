/*
** game.c for allum1 in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_allum1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Thu Feb 12 00:06:17 2015 Boulay Arnaud
** Last update Fri Feb 20 12:59:29 2015 Boulay Arnaud
*/

#include "my.h"

int		player_turn(t_game *game, t_flags *flags, char **input)
{
  int		matches;
  int		i;
  int		row;
  t_game	*tmp;

  i = 0;
  row = my_getnbr(input[0]);
  matches = my_getnbr(input[1]);
  flags->input = matches;
  tmp = game->next;
  while (++i < row && tmp != game)
    tmp = tmp->next;
  if (tmp == game || row < 1 || matches < 1)
    {
      my_putstr("Invalid row or matches, try again please.\n");
      return (-1);
    }
  if (tmp->matches - matches < 0)
    {
      my_putstr("You are trying to take too much matches, try again please.\n");
      return (-1);
    }
  tmp->matches = tmp->matches - matches;
  flags->matches = flags->matches - matches;
  return (0);
}

int		ai_core(t_game *game, t_game *tmp, t_flags *flags, int *matches)
{
  if (check_final(game) == 1)
    return (1);
  if (tmp->matches - *matches < 0)
    {
      *matches = *matches - 2;
      if (*matches < 1)
	*matches = 1;
    }
  else
    {
      tmp->matches = tmp->matches - *matches;
      flags->matches = flags->matches - *matches;
      return (1);
    }
  return (0);
}

int		ai_turn(t_game *game, t_flags *flags)
{
  t_game	*tmp;
  static int	row = 1;
  int		matches;
  int		i;

  matches = flags->input + 1;
  if ((flags->matches % 2 == 1 && matches % 2 == 0) ||
      (flags->matches % 2 == 0 && matches % 2 == 1))
    ++matches;
  while (matches > 0)
    {
      tmp = game->next;
      i = 0;
      while (++row <= flags->row)
	{
	  while (++i != row)
	    tmp = tmp->next;
	  if (ai_core(game, tmp, flags, &matches) == 1)
	    return (0);
	  tmp = tmp->next;
	}
      row = 1;
    }
  return (-1);
}
