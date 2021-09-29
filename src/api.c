#include "api.h"
#include "load_map.h"
#include "find_square.h"
#include "print_map.h"
#include "utility.h"

int	run(const char *path)
{
	t_map	mapinfo;
	char	**map;

	map = NULL;
	if (load_map(path, map, &mapinfo) == FAIL)
	{
		if (map != NULL)
			free(map);
		return (FAIL);
	}
	find_square(map, &mapinfo);
	print_map(map);
	free(map);//TODO
	return (SUCCESS);
}

void	print_error(void)
{
	int			i;
	const char	*msg = "map error\n";

	i = 0;
	while (msg[i] != '\0')
	{
		write(1, &msg[i], 1);
	}
}
