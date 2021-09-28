#include "api.h"
#include "load_map.h"
#include "find_square.h"
#include "print_map.h"
#include "utility.h"

int	run(const char *path)
{
	t_cset	cset;
	//todo
	char	**map;

	if (load_map(path, map, &cset) == FAIL)
	{
		if (map != '\0')
			free(map);
		return (FAIL);
	}
	find_square(map, cset);
	print_map(map);
	free(map);
	return (SUCCESS);
}

void	print_error(void)
{
	int			i;
	const char *msg = "map error\n";

	while (msg[i] != '\0')
	{
		write(1, &msg[i], 1);
	}
}