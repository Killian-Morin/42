#include <unistd.h>

/*
Take a single string and write it without whitespaces (spaces/tabs) at the beginning and the end and with each word separated by 3 spaces.
*/

int	ignore_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int	word_len(char *str)
{
	int	i = 0;

	while (str[i] != ' ' && str[i] != '\t' && str[i])
		++i;
	return (i);
}

void    expand_str(char *str)
{
	int	i = 0;
	int	len;
	int	first_word = 1;//signal for the first word to not put the spaces before

	i = ignore_whitespace(str, i);//ignore the whitespaces before the first word
	while (str[i] != '\0')
	{
		len = word_len(str + i);//get the len of the word with the current index
		if (len > 0 && first_word == 0)//if a new word (len > 0 means not at the end of the string) and the signal has been changed (not the first word, with no need to write spaces)
			write(1, "   ", 3);
		first_word = 0;//change the signal after the first iteration/word so that all following iteration/word will have the spaces before
		write(1, str + i, len);//write the word
		i += len;//add the length of the word to the index to pass to the next word
		i = ignore_whitespace(str, i);//ignore the whitespaces that are between words   
	}
}
