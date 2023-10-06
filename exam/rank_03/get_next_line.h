#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10//means that will we read 10 caras per call
# endif

char    *get_next_line(int fd);

#endif
