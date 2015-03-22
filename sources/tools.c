/*
** tools.c for allum1 in /home/boulay_b/Work/cprogelem/Allum1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Tue Feb 10 17:44:00 2015 Boulay Arnaud
** Last update Sun Feb 15 15:49:11 2015 Boulay Arnaud
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    my_putchar(str[i]);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  while (str[++i] != '\0')
    if (str[i] < '0' || str[i] > '9')
      return (-1);
    else if (str[i + 1] == '\0')
      nb = nb + (str[i] - 48);
    else
      nb = (nb * 10) + ((str[i] - 48) * 10);
  return (nb);
}

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + 48);
}

int	my_strcmp(char *str, char *src)
{
  int	i;

  i = -1;
  if (str == NULL || src == NULL)
    return (-1);
  while (src[++i] != '\0')
    if (src[i] != str[i])
      return (0);
  return (1);
}
