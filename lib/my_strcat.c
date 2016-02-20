/*
** my_strcat.c for strcat in /home/amira_s/jour04_C/amira_s
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Fri Jan  22 16:23:25 2015 AMIRA Syrine
** Last update Fri Jan  22 16:45:07 2015 AMIRA Syrine
*/

#include "../src/my.h"

char	*my_strcat(char *str1, char *str2)
{
	int	i;
	int	j;
	char *newstr;

	i = 0;
	j = my_strlen(str1);
	newstr = malloc(15 * sizeof(char));
	while (i < my_strlen(str1))
	{	
		newstr[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < my_strlen(str2))
		newstr[j++] = str2[i++];
	newstr[j] = '\0';
	return (newstr);
}
