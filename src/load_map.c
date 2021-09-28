#include "load_map.h"
#include "utility.h"
#include "file_io.h"


// 계산할 때 좀 더 쉽게 계산하게 하기 위해 줄바꿈 문자를 처음에는 제거하고, 프린트할때 다시 계산해야 할듯.
// 맵을 바깥쪽에서 넣어줄 방법이 마땅치 않기 때문에, **map을 load 맵 안으로 넣는것이 좋을듯.
// 아마 read_file에 마지막에 널 문자를 넣는것을 생각해 봐야 할듯..?
int	load_map(const char *path, char ***map, t_map *mapinfo)
{
	int size;
	char *one_line_map;
	int is_read_file;
	int is_valid_map;
	int is_valid_words;

	size = get_file_size(path);
	one_line_map = (char *)malloc(sizeof(char) * size + 1);
	if (one_line_map == NULL)
		return (FAIL);
	is_read_file = read_file(path, one_line_map, size);
	is_valid_map = get_map_and_words(one_line_map,mapinfo,map);
	if (is_read_file == FAIL || is_valid_map == FAIL)
	{
		free(one_line_map);
		return (FAIL);
	}
	set_map(map, one_line_map);
	free(one_line_map);
	return (SUCCESS);
}

int get_map_and_words(char *one_line_map, t_map *mapinfo, char ***map)
{
	int i;
	int is_valid;

	i = 0;
	while (one_line_map[i] != '\0' && one_line_map[i] != '\n')
	{
		if (i = 0)
			mapinfo -> height = one_line_map[i];
		if (i = 1)
			mapinfo -> empty = one_line_map[i];
		if (i = 2)
			mapinfo -> obstacle = one_line_map[i];
		if (i = 3)
			mapinfo -> area = one_line_map[i];
		i++;
	}
	if (i != 4)
		return (FAIL);
	is_valid = valid_words(mapinfo);
	if (is_valid == FAIL)
		return (FAIL);
	is_valid = is_valid_map(one_line_map, mapinfo, map);
	if (is_valid == FAIL)
		return (FAIL);
	return (SUCCESS);
}
int	valid_words (t_map *mapinfo)
{
	int i;
	int j;
	int is_duplicate;
	int words1;
	int words2;

	i = 1;
	while (i < 4)
	{
		if (i = 1)
			words1 = mapinfo -> empty;
		if (i = 2)
			words1 = mapinfo -> obstacle;
		if (i = 3)
			words1 = mapinfo -> area;
		if (!(words1 > 32 && words1 < 128))
			return (FAIL);
		j = i + 1;
		while (j < 4)
		{
			if (j = 2)
				words2 = mapinfo -> obstacle;
			if (j = 3)
				words2 = mapinfo -> area;
			if (words1 == words2)
				return (FAIL);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int is_valid_map(char *one_line_map, t_map *mapinfo, char ***map)
{
	int i;
	int j;
	int width;
	int check_width;
	const int map_height = mapinfo -> height;
	char **temp_map;

	i = 4;
	j = 0;
	width = 0;
	temp_map = *map;
	check_width = 0;
	if (one_line_map[i++] != '\n')
		return (FAIL);
	while (one_line_map[i] != '\0' && one_line_map[i] != '\n')
	{
		width++;
		i++;
	}
	i++;
	while (j < map_height && one_line_map[i] != '\0')
	{
		if (one_line_map[i] == '\n')
		{
			if (check_width != width)
				return (FAIL);
			check_width = 0;
			j++;
		}
		check_width++;
		i++;
	}
	temp_map = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (temp_map == NULL)
		free(temp_map);
		return (FAIL);
	i = 0;
	while(i < map_height)
	{
		temp_map[i] = (char *)malloc(sizeof(char ) * (width + 1));
		if (temp_map[i] == NULL)
			return (FAIL);
		i++;
	}

	return (SUCCESS);
}

void	set_map(char ***map, char *one_line_map)
{
	char** temp_map;
	int i;
	int j;
	int k;

	i = 5;
	j = 0;
	k = 0;
	temp_map = (*map);
	while(one_line_map[i] != '\0')
	{
		if (one_line_map[i] == '\n')
		{
			i++;
			j++;
			k = 0;
			continue;
		}
		map[j][k] = one_line_map[i];
		i++;
		k++;
	}
}
