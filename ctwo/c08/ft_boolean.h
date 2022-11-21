#ifndef __FT_BOOLEAN_H__

#define __FT_BOOLEAN_H__

#include <unistd.h>

#define ODD_MSG "I have an odd number of arguments.\n"
#define EVEN_MSG "I have an even number of arguments.\n"

#define SUCESS 1
#define FAILURE 0
#define FALSE 0
#define TRUE 1

typedef int t_bool;

#define EVEN(var) (var % 2)

#endif
