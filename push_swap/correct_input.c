/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:51:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/01/09 13:51:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_for_duplicate(char **argv)
{
    int i;
    int j;
    char temp;

    i = 0;
    j = 0;
    while (*argv[i])
    {
        while(argv[i][j])
        {
            temp = argv[i][j];
            if (temp = argv[i][j + 1])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int check_correct_value(char **argv)
{
    int nb_element;
    int i;

    nb_element = 0;
    i = 1;
    while (*argv[i])
    {
        while (argv[i][nb_element])
        {
            if (argv[i][nb_element] < 2147483647 && argv[i][nb_element] > -2147483648)
                return (1);
            else
                return (0);
            nb_element++;
        }
        i++;
    }
    if (check_for_duplicate(argv) == 0)
        return (0);
    return (1);
}