#include "so_long.h"

int map_length(int fd)
{
    int length = 0;
    int read_int = 1;
    char *buffer;
    int i=0;


    read_int = read(fd, buffer, BUFFER_SIZE);
    if (!read_int)
        return 0;
    while (i <  )
    {
        length += 1;
        i++;
        //read_int = read(fd, buffer, 10);
    }
    return (length);
}

int main()
{
    int fd = open("map.ber",O_RDONLY);
    printf("%d", map_length(fd));
}