/*
** my_putstr.c for putstr in /home/amira_s/libmy
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Mon Oct  5 10:01:45 2015 AMIRA Syrine
** Last update Mon Oct  5 20:43:56 2015 AMIRA Syrine
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    write(1, (str + i++), 1);
}
