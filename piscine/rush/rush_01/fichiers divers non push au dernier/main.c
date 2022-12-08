/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:36:01 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/23 13:39:15 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void    tableau(int x, int y)
{
    int    tab[4][4];
    int current_col;
    int current_line;
    
    current_line = 1;
    while (*tab[x] <= 4)
    {
        current_col = 1;
        while (*tab[y] <= 4)
        {
            write(1, "0 ", 2);
            current_col++;
        }
        write(1, "\n", 1);
        current_line++;
    }
}

int    main(int argc, char *argv[])
{
    int    i;
    char    *ptr;
    char    array[argc];
    
    i = 0;
    while (&argv[1][i] != (void *)0)
    {
        array[i] = *argv[i];
        i++;
    }
    //array[i] = malloc(16 * 1);
    i = 0;
    if (argc == 2)
    {
        if (argv[1][i] != 31)
        {
            write(1, "Error\n", 6);
        }
        else
        {
            i = 0;
            while (argv[1][i] != '\0')
            {
                if (argv[1][i] != '1' || (argv[1][i] != '2') ||
                        (argv[1][i] != '3') || (argv[1][i] != '4') ||
                            (argv[1][i] != ' '))
                {
                    write(1, "Error\n", 6);
                    return (0);
                }
                i = i + 2;
                tableau(4, 4);
            }
        }
    }
    else if (argc != 2)
    {
        write(1, "Error\n", 6);
    }
    free(&ptr);
}
