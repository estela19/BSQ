#ifndef FILE_IO_H
# define FILE_IO_H

# include<unistd.h>
# include<fcntl.h>
# include<string.h>

# define SIZE 100000

int		read_file(const char *path, char *buff);
void	print(char *str);
void	print_char(char *c);

#endif