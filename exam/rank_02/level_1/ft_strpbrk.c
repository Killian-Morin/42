#include <unistd.h>

/*
Take two strings in parameters, and search for the first occurrence of any char present in s2/charset, in s1. Once a char is found, the rest of s1 is returned, else NULL.
*/

char	*ft_strpbrk(const char *s1, const char *s2)
{
	if (!s1 || !s2)//if one string is null then not bother to check
		return (NULL);

	int	i;

	while (*s1)//iterate through s1
	{
		i = 0;
		while (s2[i])//iterate through the charset/where we have the char that we are looking for
		{
			if (*s1 == s2[i])//if same char
				return (char *) s1;//return the rest of the s1
			i++;
		}
		s1++;
	}
	return (NULL);//didn’t find a char of s2 in s1 so NULL
}
