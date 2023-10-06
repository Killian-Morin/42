#include <unistd.h>

/*
Take a string and display the string after rotating it one word to the left. The first word becomes the last and the second word becomes the first. A word is delimited by whitespaces (spaces/tab) and by the start/end of the string.
The program passes the first word, then writes all the words, then writes the first word.
*/

int	ft_whitespace(char *str, int i)//iterates through all the char that are either spaces or tab
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int	len_word(char *str)//iterates until meeting a space, a tab or the end of string to return the length of a word
{
	int	i = 0;

	while (str[i] != ' ' && str[i] != '\t' && str[i])
		i++;
	return (i);
}

int	print_word(char *str, int i, int *signal)
{
	int	len;

	i = ft_whitespace(str, i);//ignore the whitespaces that can be before the word (mainly because of printing the first word that can have whitespaces before it that are not ignore in the loop of epur())
	len = len_word(str + i);//get the len of the word at the current index
	if (*signal == 0)//signal != 0 only during the first iteration, thus for the second word that will not have a space before
		write(1, " ", 1);
	write(1, str + i, len);//write the whole word
	*signal = 0;//modify the signal for writing a space for each of the following iteration/for each following words
	return (i + len);//return the index where begins the next delimitation (whitespace, end of string)
}

int	epur(char *str)
{
	int	i = 0;
	int	signal = 1;//set it up for the first iteration that will not display a space

	i = ft_whitespace(str, i);//ignore the whitespaces that are before the first word passed (the second word of av[1])
	while (str[i])//iterates through the whole string for writing all the words (exclude the first word that will be write after exiting this loop)
	{
		i = print_word(str, i, &signal);//writes the current word and gets the index for the end of the word that has just been write
		i = ft_whitespace(str, i);//ignore the whitespaces that can be between the words
	}
	return (signal);//return the signal that is == 0 for the last word to be printed (previously the first word)
}

int	main(int ac, char **av)
{
	if (ac >= 2)//if they are more than 2 arg it will just display the first arg
	{
		int		i = 0;
		char	*tmp = av[1];//takes the string or the first string if they are multiple arg
		int		signal;

		i = ft_whitespace(tmp, i);//iterates through the whitespaces before the first word
		i += len_word(tmp + i);//iterates through the first word to arrive at the start of the second word/the new first word
		signal = epur(tmp + i);//this will write all the words except the first word
		print_word(tmp, 0, &signal);//writes the first word (thanks to the 0 for the index on tmp and signal for the space), it will be display last so indeed rotating the print
	}
	write(1, "\n", 1);
	return (0);
}
