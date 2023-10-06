/*
write the last word of the string passed in arguments | a word is delimited by start/end of the string and whitespaces.
*/

int	main(int ac, char **av)
{
	int	i = 0;

	while (av[1][i] != '\0')//iterate to arrive at the end of the string
		i++;
	i--;
	while ((av[1][i] == ' ' || av[1][i] == '\t') && i != 0)//iterate through the whitespaces at the end of the string
		i--;
	while (av[1][i] != ' ' && av[1][i] != '\t' && i != 0)//iterate through the last word until meeting the start of the string or a whitespace
		i--;
	if (av[1][i] == ' ' || av[1][i] == '\t')//if the current char is a whitespace, then iterate to ignore it
		i++;
	while (av[1][i] != '\0' && av[1][i] != ' ' && av[1][i] != '\t')//write the word until meeting the end of string or a whitespace
	{
		write(1, &av[1][i], 1);
		i++;
	}
}
