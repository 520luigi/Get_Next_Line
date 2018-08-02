#include "get_next_line.h"

int   main(int ac, char **av)
{
  char *line;
  int fd;

  fd = open(av[1], O_RDONLY);
  get_next_line(fd, &line);
  printf("%s\n", line);
	get_next_line(fd, &line);
  printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
  return (0);
}
