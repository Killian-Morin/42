#include <unistd.h>
#include <stdlib.h>

/*
Takes a string and needs to split it words | a word is delimited by spaces/tab/new lines or by the start or end of the string | si segfault c’est surement car je met des ou (||) à la place de et (&&) ds les conditions ou ce sont les sizeof() ds les malloc
*/

int	ft_nb_mot(char *str)
{
	int	i = 0;
	int	res = 1;//there is always at least one word

	while (str[i])//parse the whole str
	{
		if (str[i] != ' ' && str[i] != '\t')//the char is not a whitespace (not a space AND not a tab)so it’s a new word (since escaped the while of this if)
		{
			res++;
			while (str[i] != ' ' && str[i] != '\t' && str[i])//iterates until meeting a whitespace or end of string then leaves this loop
				i++;
		}
		else//found a whitespace earlier so escaped from the if and needs to iterate the str to pass the whitespaces between words
			i++;
	}
	return (res);
}

int	*ft_len(char *str, int nb)
{
	int	i = 0;
	int	len = 0;
	int	j = 0;
	int	*tab;

	tab = malloc(sizeof(int) * nb);//malloc with the exact nb of words
	if (!tab)
		return (NULL);
	while (str[i])//parse the whole str
	{
		if (str[i] != ' ' && str[i] != '\t')//the char is not a whitespace (not a space AND not a tab) so it’s a new word
		{
			len = 0;
			while (str[i] != ' ' && str[i] != '\t' && str[i])//iterates both until meeting a whitespace or the end of str
			{
				i++;
				len++;
			}
			tab[j++] = len + 1;//add one for the ‘\0’ and pass to the next word (j++)
		}
		else//found a whitespace earlier so escaped from the if and needs to iterate the str or whitespaces between words
			i++;
	}
	return (tab);
}

char	**ft_fill(char *str, char **res, int *len)
{
	int	i = 0;
	int	j = 0;
	int	k;

	while (str[i])//parse the whole str
	{
		if (str[i] != ' ' && str[i] != '\t')//the char is not a whitespace (not a space AND not a tab) so a new word/string of the array of string
		{
			res[j] = malloc(sizeof(char) * len[j]);//malloc the string of this word / will fill this string with char so sizeof(char)
			if (!res)
				return (NULL);
			k = 0;
			while (str[i] != ' ' && str[i] != '\t' && str[i])//until meeting a whitespace or the end of the string copy str in res
				res[j][k++] = str[i++];
			res[j++][k] = '\0';//add a ‘\0’ at the end of the string/word and pass to the next word/next string of the array (j++)
		}
		else//found a whitespace earlier so escaped from the if and needs to iterate the str or whitespaces between words
			i++;
	}
	res[j] = NULL;//null terminating the array of string
	return (res);
}

char	**ft_split(char *str)
{
	int		nb_mot;
	int		*len;
	char	**res;

	nb_mot = ft_nb_mot(str);//get the number of words that compose the str
	len = ft_len(str, nb_mot);//get the size of each words of the str
	res = malloc(sizeof(char *) * nb_mot);//will fill this tab with string so sizeof(char *)
	if (!res)
		return (NULL);
	res = ft_fill(str, res, len);//fill the array of string
	return (res);
}
