#include <stdio.h>
#include "read_line.h"

int main(void)
{
    char *line;
//    int ret;
    char str2[10];
    read_line_2(str2, 6);
    printf("str2: %s\n", str2);
    while ((line = read_line(stdin)) != NULL) {
	printf("%s\n", line);
    }
    free_buffer();
}

