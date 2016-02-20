/*
** my_getnbr.c for getnbr in /home/amira_s/libmy
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Mon Oct  5 09:57:22 2015 AMIRA Syrine
** Last update Mon Oct  5 20:42:59 2015 AMIRA Syrine
*/

#include <unistd.h>

int	my_strlen(char *str);

int	my_getnbr(char *str)
{
  int	i;
  int	s;
  int	x;

  i = 0;
  s = 1;
  x = 0;
  while (!(str[i] <= '9' && str[i] >= '0'))
    {
      if (str[i] == '+')
	s *= 1;
      else if (str[i] == '-')
	s *= -1;
      else
	return (0);
      i++;
    }
  while (str[i] <= '9' && str[i] >= '0')
    {
      x *= 10;
      x += (int)str[i++] - 48;
    }
  return (x * s);
}
