// #include "get_next_line.h"

#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(void)
{
    int fd;
    int i;
    char *filename;

    filename = "Text.txt";  
    i = 0;
    char read_array [BUFFER_SIZE];
    //char *line_array;

    fd = open (filename, O_RDONLY);
    if (fd == 0)
    {
      write (1, "File Error\n", 11);
      return (0);
    }
    // get_next_line(fd);
    while (read(fd, &read_array, BUFFER_SIZE))
    {
        write (1, &read_array, BUFFER_SIZE);
    }
    close (fd);
    return (0);
}
// 
// char    *get_next_line(int fd)
// {

// }
