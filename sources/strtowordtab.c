/*
** strtowordtab.c for allum1 in /home/boulay_b/Rendu/SE2/CPE/CPE_2014_allum1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Wed Feb 11 23:32:18 2015 Boulay Arnaud
** Last update Sun Feb 15 16:17:06 2015 Boulay Arnaud
*/

#include <stdlib.h>
#include "my.h"

int		count_words(char *str, char sep)
{
  int		words;
  int		i;

  i = -1;
  words = 0;
  while (str[++i] != '\0')
    if ((str[i] != sep && str[i] != '\t') &&
	(str[i + 1] == sep || str[i + 1] == '\t' || str[i + 1] == '\0'))
      ++words;
  return (words);
}

int		my_wordlen(char *str, int *i, char sep)
{
  int		j;

  j = 0;
  while (str[++*i] != '\0')
    if (str[*i] != sep && str[*i] != '\t')
      {
	++j;
	if (str[*i + 1] == sep || str[*i + 1] == '\t' || str[*i + 1] == '\0')
	  return (j);
      }
  return (-1);
}

char		*my_wordcpy(char *tab, char *str, int *i, char sep)
{
  int		j;

  j = -1;
  while (str[++*i] != '\0')
    if (str[*i] != sep && str[*i] != '\t')
      {
	tab[++j] = str[*i];
	if (str[*i + 1] == sep || str[*i + 1] == '\t' || str[*i + 1] == '\0')
	  {
	    tab[++j] = '\0';
	    return (tab);
	  }
      }
  return (NULL);
}

char		**my_strtowordtab(char **tab, char *str, char sep)
{
  int		words;
  int		i;
  int		j;
  int		k;

  i = -1;
  j = -1;
  k = -1;
  if (str == NULL)
    return (NULL);
  words = count_words(str, sep);
  if ((tab = malloc(sizeof(char *) * (words + 1))) == NULL)
    return (NULL);
  while (++i < words)
    {
      if ((tab[i] = malloc(sizeof(char) * (my_wordlen(str, &j, sep) + 1)))
	  == NULL)
	return (NULL);
      tab[i] = my_wordcpy(tab[i], str, &k, sep);
    }
  tab[i] = NULL;
  return (tab);
}

int		free_tab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i] != NULL)
    free(tab[i]);
  free(tab[i]);
  free(tab);
  return (0);
}
