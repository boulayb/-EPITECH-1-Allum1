/*
** main.c for allum1 in /home/boulay_b/Work/cprogelem/Allum1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Tue Feb 10 15:32:30 2015 Boulay Arnaud
** Last update Tue Feb 17 11:35:57 2015 Boulay Arnaud
*/

#include <stdlib.h>
#include "my.h"

int		my_allum1(t_game *game, t_flags *flags)
{
  char		**input;
  char		*str;

  my_putstr("\nRelaunch with a first argument to change the number of row.\n");
  my_putstr("Relaunch with -p as a second argument to play \"Player Versus Player\".\n");
  disp_turn(game, flags);
  disp_game(game, flags);
  my_putstr("\nEnter the row and the number of matches to take: ");
  while ((str = get_next_line(0)) != NULL)
    {
      if ((input = my_strtowordtab(input, str, ' ')) == NULL)
	return (-1);
      free(str);
      if (input[0] != NULL && input[1] != NULL)
	if (player_turn(game, flags, input) != -1 && free_tab(input) == 0)
	  if (disp_turn(game, flags) == 1)
	    return (1);
      disp_game(game, flags);
      my_putstr("\nEnter the row and the number of matches to take: ");
    }
  my_putstr("Error: Read failed.\n");
  return (0);
}

int		main(int ac, char **av)
{
  t_flags	*flags;
  t_game	*game;
  int		row;

  flags = NULL;
  row = 5;
  if (ac == 2)
    {
      row = my_getnbr(av[1]);
      if (row < 2 || row > 42)
	{
	  my_putstr("Error: row must be set between 2 and 42.\n");
	  return (-1);
	}
    }
  if ((game = create_game(row)) == NULL ||
      (flags = init_struct(game, flags, av)) == NULL ||
      my_allum1(game, flags) == -1)
    {
      my_putstr("Error: Malloc failed.\n");
      return (-1);
    }
  free_all(game, flags);
  return (0);
}
