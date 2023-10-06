#include <unistd.h>

/*
Spans s as long as the char from s does occur in accept, it returns the number of char spanned.
*/

char	*ft_strchr(const char *s, int c)//will check every char of s and if no char of s is equal to c then return 0 else return the rest of the string
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i = 0;

	while (s[i])//parse the whole string
	{
		if (ft_strchr(accept, s[i]) == 0)//if the char is not found return the number of char spanned
			return (i);
		i++;
	}
	return (i);//arrived at the end of s so spanned all char
}
