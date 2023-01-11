#include <stdio.h>
#include <stdlib.h>

/*main pour tester correct input*/
int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		printf("%d\n", check_correct_value(argv));
		printf("%d\n", check_for_duplicate(argv));
	}
	return (0);
}
