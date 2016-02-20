/*
** my_putnbr.c for putnbr in /home/amira_s/libmy
** 
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
** 
** Started on  Mon Oct  5 09:57:55 2015 AMIRA Syrine
** Last update Mon Oct  5 20:33:25 2015 AMIRA Syrine
*/

void	my_putchar(char c);

void	my_putstr(char *str);

void	my_put_nbr(int n)
{
  int	c;
  int	x;

  c = 1;
  if (n == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (n < 0)
	{
	  my_putchar('-');
	  n = -n;
	}
      while (n / c >= 10)
	{
	  c *= 10;
	}
      while (c > 0)
	{
	  x = (n / c) % 10;
	  my_putchar(x + '0');
	  c /= 10;
	}
    }
}
