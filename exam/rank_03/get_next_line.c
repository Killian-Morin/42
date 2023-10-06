#include <unistd.h>
#include <stdlib.h>
#include "./get_next_line.h"

/*
	PASSE grademe
*/

int	gnl_strlen(char *str)//strlen classic
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	gnl_strchr(char *str, int c)//strchr classic that search for the char c in str if found return 1 else return 0
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *stock, char *buffer)//create a new string and add stock to it, then buffer with a \0 and returns it | no free when error
{
	char	*str;
	int		i;
	int		j;
	int		size;

	if (!stock)//no char saved so initialize stock with a \0 
	{
		stock = (char *)malloc(sizeof(char) * 1);
		stock[0] = '\0';
	}
	size = gnl_strlen(stock) + gnl_strlen(buffer);
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (!str)
	{
		free(stock);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (stock[i])//copy stock to the new string
		str[j++] = stock[i++];
	i = 0;
	while (buffer[i])//copy buffer to the new string
		str[j++] = buffer[i++];
	str[j] = '\0';//signal the end of string
	free(stock);//free the precedent stock since it will be updated with the string returned (stock + buffer)
	return (str);
}

char	*gnl_update_stock(char *stock)//need to remove from stock the line that will be returned | always a free when error
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	while (stock[i] != '\0' && stock[i] != '\n')//iterate through the first line or the whole file if no \n at the end a line
		i++;
	if (stock[i] != '\n')//check if at the right place, the end of the line
	{
		free(stock);
		return (NULL);
	}
	i++;//iterate through it to adjust the index
	str = (char *)malloc(sizeof(str) * (gnl_strlen(stock) - i + 1));//get the len of stock, - i to remove the line and + 1 to add a \0
	if (!str)
	{
		free(stock);
		return (NULL);
	}
	k = 0;
	while (stock[i])//copy stock (from the index i to ignore the first line) to new that will be the new stock
		str[k++] = stock[i++];
	str[k] = '\0';//signal the end of string
	free(stock);//free the previous stock
	return (str);
}

char	*gnl_line(char *stock)//need to take the first line of stock to return it | can be a free when error but not mandatory
{
	int		i;
	char	*line;

	i = 0;
	if (*stock == '\0')//if stock is empty then will simply print (null)
		return (NULL);
	while (stock[i] != '\0' && stock[i] != '\n')//iterate through the first line or the whole file if no \n at the end a line
		i++;
	line = (char *)malloc(sizeof(line) * (i + 1));
	if (!line)
	{
		free(stock);
		return (NULL);
	}
	i = 0;//restart from the start of stock to copy the first line
	while (stock[i] != '\0' && stock[i] != '\n')//copy the first line
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')//if a new line and not the end of file we need to put it in the line
		line[i++] = '\n';
	line[i] = '\0';//signal the end of string
	return (line);
}


char	*gnl_stock(int fd, char *stock)//always a free when error
{
	int checker;
	char    *buffer;

	checker = 1;
	buffer = (char *)malloc(sizeof(buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(stock);
		return (NULL);
	}
	while (gnl_strchr(stock, '\n') != 1 && checker != 0)//until meeting the end of a line or the end of the file (return of read will be 0)
	{
		checker = read(fd, buffer, BUFFER_SIZE);//copy the char read from the fd to buffer for buffer_size number of char
		if (checker == -1)//error during the read
		{
			free(stock);
			free(buffer);
			return (NULL);
		}
		buffer[checker] = '\0';//put a \0 for easier access later on
		stock = gnl_strjoin(stock, buffer);//add what has just been read to the possible rest of the precedent call
	}
	free(buffer);//we arrive at the end of the line/file so free that since all as already been copied to stock
	return (stock);
}

char	*get_next_line(int fd)//no free when error
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE < 0)//check for a valid fd or size to read
		return (NULL);
	stock = gnl_stock(fd, stock);//get the characters read from the fd
	if (!stock)
		return (NULL);
	line = gnl_line(stock);//get the first line of that has been read
	stock = gnl_update_stock(stock);//remove the first line that has been read and save the rest of the characters that has been read for the next call of get_next_line()
	return (line);//return the first line that has been read
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		i;
	int		fd;
	char	*line;	


	i = 0;
	fd = open("get_next_line.c", 0);
	while (i != 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}*/
