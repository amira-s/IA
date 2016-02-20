/*
** my_putchar.c for putchar in /home/amira_s/libmy
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Mon Oct  5 09:59:52 2015 AMIRA Syrine
** Last update Mon Oct  5 10:00:02 2015 AMIRA Syrine
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
