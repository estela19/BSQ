#ifndef UTILITY_H
# define UTILITY_H

# include <unistd.h>

# define SUCCESS 0
# define FAIL -1

# define TRUE 1
# define FALSE 0

typedef struct s_area{
	int	x;
	int	y;
	int	len;
}t_area;

int		ft_strlen(char *str);
void	ft_strcpy(char *dest, char *src);

#endif