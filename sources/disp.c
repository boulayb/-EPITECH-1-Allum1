/*
** disp.c for allum1 in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_allum1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Wed Feb 11 23:27:30 2015 Boulay Arnaud
** Last update Tue Feb 17 12:07:44 2015 Boulay Arnaud
*/

#include <stdlib.h>
#include "my.h"

int			disp_victory(t_game *game, t_flags *flags)
{
  if (check_victory(game) == 1)
    {
      if (flags->pvp == 1)
	{
	  if (flags->turn == 0)
	    my_putstr("\nPlayer1 win!\n");
	  else if (flags->turn == 1)
	    my_putstr("\nPlayer2 win!\n");
	}
      if (flags->pvp == 0)
	{
	  if (flags->turn == 0)
	    my_putstr("\nPlayer2 win!\n");
	  else if (flags->turn == 1)
	    my_putstr("\nPlayer1 win!\n");
	}
      return (1);
    }
  return (0);
}

void			disp_spaces(int matches, int spaces, int line)
{
  int			i;

  i = -1;
  if (matches < 10)
    my_putstr("  ");
  else
    my_putchar(' ');
  if (line < 10)
    my_putchar(' ');
  while (++i < spaces)
    my_putchar(' ');
}

void			disp_game(t_game *game, t_flags *flags)
{
  int			spaces;
  t_game		*tmp;
  int			line;
  int			i;

  line = 0;
  tmp = game->next;
  spaces = flags->max_spaces;
  while (tmp != game)
    {
      i = -1;
      my_putnbr(++line);
      my_putstr(" - ");
      my_putnbr(tmp->matches);
      disp_spaces(tmp->matches, spaces, line);
      --spaces;
      while (++i < tmp->matches)
	my_putchar('|');
      my_putchar('\n');
      tmp = tmp->next;
    }
}

int			disp_turn(t_game *game, t_flags *flags)
{
  if (disp_victory(game, flags) == 1)
    return (1);
  if (flags->turn != -1 && flags->pvp == 0)
    flags->turn = 1;
  if (flags->turn == -1 || (flags->turn == 0 && flags->pvp == 1))
    {
      my_putstr("\nIt is player1 turn.\n\n");
      flags->turn = 1;
      return (0);
    }
  if (flags->turn == 1)
    {
      my_putstr("\nIt is player2 turn.\n\n");
      if (flags->pvp == 0)
	{
	  my_putstr("AI is playing.\n");
	  ai_turn(game, flags);
	  if (disp_victory(game, flags) == 1)
	    return (1);
	  my_putstr("\nIt is player1 turn.\n\n");
	}
      flags->turn = 0;
    }
  return (0);
}
