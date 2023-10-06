int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])//iterate through the strings, stopping when arriving at the end of one of the strings or meeting a char ≠ between the two
		i++;
	return (s1[i] - s2[i]);//return the difference between the two
}
