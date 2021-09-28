# BSQ  

# Layer  
**api** <-> **map_manager** <-> **file_io**  

## api layer  
하나의 map에 대해 최대공간을 구한다.  

``` 
int run(const char *path);
void print_error(void);
```  

## map_manager layer  
map에 대한 연산을 수행.  
**load_map**, **find_square**, **print_map**, **utility** 로 구성되어 있다. 
```
int load_map(const char *path, char **map)
void find_square(char **map, struct *locate)
void print_map(char **map, t_area area);
```  
  
  
  * load_map  
   인자로 받은 주소파일을 읽고 유효한 파일인지 확인 후 유효할경우 map에 넣어준다.  
     
 * find_square  
   핵심 logic 함수. map에서 최대 사각형 공간을 구하고, 그 공간의 좌상단의 좌표와 변의 길이를 locate에 담아준다.  

* print_map  
	인자로 받은 map에 area를 표시해준 후 출력한다.  
   

### utility   
여러가지 유틸함수, area 구조체, 상태들이 정의되어 있다.
``` 
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
```
  
 ## file layer  
  직접적인 file io를 담당하는 부분  

  ```
	int	read_file(const char *path, char *buff);
	void	print(char *str);
	void	print_char(char *c);
  ```

 * read_file 
   path에 해당하는 파일 내용을 buff에다가 담아준다.  
   성공시 SUCCESS, 실패시 FAIL을 반환한다. 
     
 * print
   인자로 받은 string을 출력해준다. 

 * print_char
   인자로 받은 char 한 글자를 출력해준다. 
