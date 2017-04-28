/*
** gnl.h for  in /home/jamie/get_next_line
** 
** Made by James Faure
** Login   <james.faure@epitech.eu>
** 
** Started on  Fri Apr 28 16:16:55 2017 James Faure
** Last update Fri Apr 28 16:27:15 2017 James Faure
*/

#ifndef GNL_H_
# define GNL_H_

/*
** For open(2) and read(2)
*/
#include <fcntl.h>
#include <unistd.h>

#include <malloc.h>
#include <string.h>
#include <assert.h>

#ifndef READ_SIZE
# define READ_SIZE 500
#endif

int	sstrlen(char const *str);
void	*smalloca(size_t len);
char	*astrcat(char const *a, char const *b);
char	*get_next_line(int const fd);

#endif
