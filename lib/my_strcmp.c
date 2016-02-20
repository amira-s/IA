/*
** my_strcmp.c for strcmp in /home/amira_s/jour04_C/amira_s
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Thu Oct  1 11:25:37 2015 AMIRA Syrine
** Last update Mon Oct  5 20:44:39 2015 AMIRA Syrine
*/

int	my_strlen(char *str);

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (i < my_strlen(s1))
    {
      if (s1[i] < s2[i])
	  return (-1);
      else if (s1[i] > s2[i])
	return (1);
      i++;
    }
  if (s2[i] > s1[i])
    return (-1);
  else if (s2[i] < s1[i])
    return (1);
  return (0);
}
