#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int     main(void)
{
    char *str;
    int fd;
    fd = open("./get_next_line.c", O_RDONLY);

    get_next_line(fd, &str);

    printf("%s", str);
    
    get_next_line(fd, &str);

    printf("%s", str);
    get_next_line(fd, &str);

    printf("%s", str);
    get_next_line(fd, &str);

    printf("%s", str);
}