/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:58:56 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/24 13:26:49 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int current_col;
int current_line;

     x = 6;
     y = 6;
     current_line = 1;
     while (current_line <= 6)
     {
         current_col = 1;
         while (current_col <= 6)
         {
             write(1, "0 ", 2);
             current_col++;
         }
         write(1, "\n", 1);
         current_line++;
     }
 }
