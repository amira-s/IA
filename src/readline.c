/*
** asciifun.c for octocat in /home/amira_s/octo/src
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Fri Jan  22 16:23:25 2015 AMIRA Syrine
** Last update Fri Jan  22 16:45:07 2015 AMIRA Syrine
*/

#include <stdlib.h>
#include <unistd.h>

char		    *readLine()
{
    ssize_t	    ret;
    char		*buff;

    if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
        return (NULL);
    if ((ret = read(0, buff, 50)) > 1)
    {
        buff[ret - 1] = '\0';
        return (buff);
    }
    buff[0] = '\0';
    return (buff);
}
