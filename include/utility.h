#ifndef UTILITY_H
# define UTILITY_H

# include <unistd.h>

# define SUCCESS 0
# define FAIL -1

# define TRUE 1
# define FALSE 0

typedef struct s_map{
	int		height;
	int		width;
	char	empty;
	char	obstacle;
	char	area;
}t_map;

int		ft_strlen(char *str);
void	ft_strcpy(char *dest, char *src);

#endif