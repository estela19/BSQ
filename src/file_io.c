#include "file_io.h"
#include "utility.h"

int	read_file(const char *path, char *buff)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		return (FAIL);
	}
	else
	{
		read(fd, buff, SIZE);
		close(fd);
	}
	return (SUCCESS);
}

void	print(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	print_char(char *c)
{
	write(1, c, 1);
}
