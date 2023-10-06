/*
Takes a string and writes this string with exactly one space between words, with no whitespace (spaces/tab) at the start or end of the string.
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

	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i++;
	return (i);
}

void	epur(char *str)
{
	int	i = 0;
	int	signal = 1;
	int	len;

	i = ignore_whitespace(str, i);//ignore the whitespaces before the first word
	while (str[i])
	{
		if (signal == 0)//for the first pass it will ignore since initialized at 1
			write(1, " ", 1);
		len = word_len(str + i);//get the len of the word
		write(1, str + i, len);//write that word 
		i += len;//increment the index to arrive at the end of the word that has just been write
		signal = 0;//signal for putting a space at the next iteration
		i = ignore_whitespace(str, i);//ignore the whitespaces that are between words
	}
}
