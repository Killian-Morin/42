split vidéo:

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	m;
	int	len;
	int	nbstr;
	char	**bigstr;
	char	*smallstr;

	len = ft_strlen(s);
	i = 0;
	nbstr = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (s[i] == c)
				break;
			i++;
		}
		j = i;
		while (i < len)
		{
			if (s[i] != c)
				break;
			i++;
		}
		if (i > j)
			nbstr++;
	}
	bigstr = (char **)malloc(sizeof(char *) * (nbstr + 1));
	if (!bigstr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (s[i] == c)
				break;
			i++;
		}
		j = i;
		while (i < len)
		{
			if (s[i] != c)
				break;
			smallstr[k] = s[i];
			i++;
			k++;
		}
		smallstr[k] = '\0';
		bigstr[m] = malloc(sizeof(s) * k);
		if (!bigstr[m])
			return (NULL);
		m++;
	}
	return (bigstr);
}



split perso jusqu à present:

size_t	ft_countmot(char const *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == c)
			nb++;
		i++;
	}
	nb = nb + 1;
	return (nb);
}

char	*ft_small(const char *s, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		j++;
	return (ft_substr(s, i, j));
}

char	**ft_split(char const *s, char c)
{
	char	**bigstr;
	size_t	i;
	size_t	k;
	size_t	nbmot;

	nbmot = ft_countmot(s, c);
	bigstr = (char **)malloc(sizeof(char *) * (nbmot + 1));
	if (!bigstr)
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
			i++;
		else
		{
			while (s[i + 1] == c || s[i + 1])
			{
				bigstr[k] = ft_small(s, i);
				i++;
			}
			k++;
		}
		i++;
	}
	bigstr[k + 1] = NULL;
	return (bigstr);
}