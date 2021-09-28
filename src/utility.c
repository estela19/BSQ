#include "utility.h"

void	ft_strcpy(char *dest, char *src)
{
	char	*isrc;
	char	*idest;

	isrc = src;
	idest = dest;
	while (*isrc != '\0')
	{
		*idest = *isrc;
		isrc++;
		idest++;
	}
	*idest = '\0';
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}
