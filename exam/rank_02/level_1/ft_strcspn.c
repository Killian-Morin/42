#include <unistd.h>

/*
Spans s as long as the char from s does not occur in reject, it returns the number of char spanned.
*/
size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (s[i] != '\0')
	{
		k = 0;
		while (reject[k] != '\0')
		{
			if (reject[k] == s[i])//if the same char then return the number of char already read
				return (i);
			k++;
		}
		i++;
	}
	return (i);
}
