#ifndef FILE_IO_H
# define FILE_IO_H

# include<unistd.h>

int		read_file(const char *path, char *buff);
void	print(char *str);
void	print_char(char *c);

#endif