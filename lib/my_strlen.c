/*
** my_strlen.c for strlen in /home/amira_s/libmy
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Mon Oct  5 10:02:35 2015 AMIRA Syrine
** Last update Mon Oct  5 20:46:25 2015 AMIRA Syrine
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*str++ != '\0')
    i++;
  return (i);
}
