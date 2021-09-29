#include "api.h"
#include "utility.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (run(argv[i]) == FAIL)
		{
			print_error();
		}
	}
	return (0);
}
