#include "print_map.h"
#include "file_io.h"
#include "utility.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		print(map[i]);
		print("\n");
		i++;
	}
}
