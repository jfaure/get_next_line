/*
** get_next_line.c for  in /mnt/james.faure/SHELL
** 
** Made by James Faure
** Login   <james.faure@epitech.eu>
** 
** Started on  Mon Mar 27 02:02:32 2017 James Faure
** Last update Fri Apr 28 16:35:14 2017 James Faure
*/

#include "gnl.h"

/*
** Safe versions of strlen and malloc
*/
int	sstrlen(char const *str)
{
  if (str)
    return (strlen(str));
}

void	*smalloc(size_t len)
{
  void	*r;

  assert(r = malloc(len));
  return (r);
}

char	*astrcat(const char *a, const char *b)
{
  char	*r;
  char	*p;

  r = smalloc(sstrlen(a) + sstrlen(b) + 1);
  p = r;
  if (a)
    while (*a)
      *p++ = *a++;
  if (b)
    while (*b)
      *p++ = *b++;
  *p = 0;
  return (r);
}

/*
** The Main difficulty is getting the function to work with non newline terminated\
** file streams, like <(echo -en "abc \n def")
** Realloc is of course forbidden in most First year Epitech projects;
** I use the GNU strlen and strndup to avoid copying this trivial part of my lib
** Also, the norm requires functions not to exceed 25 lines...
*/
char	*get_next_line(int const fd)
{
  char		buf[READ_SIZE + 1];
  static char	*save = 0;
  static int	i = 0;
  static int	done = 1;
  int	j;
  char	*plop;

  j = i;
  if (save && done)
    while (save[i])
      if (10 == save[i++])
	return (strndup(save + j, i - j - 1));
  if (!done || fd < 0 || !(done = read(fd, buf, READ_SIZE)))
    {
      plop = save && save[j] ? strndup(save + j, i - j) : 0;
      free(save);
      save = 0;
      return (plop);
    }
  i = buf[done] = 0;
  save = astrcat((plop = save) + j, buf);
  free(plop);
  return (get_next_line(fd));
}

/*
** Example use
*/
int	main(int ac, char **av)
{
  --ac && (ac = open(av[1], O_RDONLY));
  while (*av = get_next_line(ac))
    {
      puts(*av);
      free(*av);
    }
  return (0);
}
