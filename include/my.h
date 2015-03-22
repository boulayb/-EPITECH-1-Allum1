/*
** my.h for allum1 in /home/boulay_b/Work/cprogelem/Allum1
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Tue Feb 10 15:32:03 2015 Boulay Arnaud
** Last update Fri Feb 20 02:27:46 2015 Boulay Arnaud
*/

#ifndef	MY_H_
# define MY_H_

# define BUFFER_SIZE	4096

typedef struct		s_game
{
  int			matches;
  struct s_game		*next;
  struct s_game		*back;
}			t_game;

typedef struct		s_flags
{
  int			row;
  int			turn;
  int			matches;
  int			input;
  int			pvp;
  int			max_spaces;
}			t_flags;

int			my_getnbr(char *str);
int			check_victory(t_game *game);
int			check_final(t_game *game);
int			player_turn(t_game *game, t_flags *flags, char **input);
int			disp_turn(t_game *game, t_flags *flags);
int			my_strcmp(char *str, char *src);
int			free_tab(char **tab);
int			ai_turn(t_game *game, t_flags *flags);
char			*get_next_line(const int fd);
char			**my_strtowordtab(char **tab, char *str, char sep);
void			disp_game(t_game *game, t_flags *flags);
void			my_putchar(char c);
void			my_putstr(char *str);
void			my_putnbr(int nb);
void			rm_list(t_game *game);
void			free_all(t_game *game, t_flags *flags);
t_game			*create_game(int row);
t_flags			*init_struct(t_game *game, t_flags *flags, char **av);

#endif /* !MY_H_ */
