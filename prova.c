#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(){

    int fd = open("testo.txt", O_RDONLY);
    int i;

    i = 0;
    while (i < 9){
    char *str = get_next_line(fd);
    //char *str1 = get_next_line(fd);
    printf("%s", str);
    free(str);
    i++;
    }
    return (0);
}
