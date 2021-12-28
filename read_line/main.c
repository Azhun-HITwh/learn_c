#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"

int main(void)
{
    char *line;
    char *str2 = malloc(sizeof(char) * 6);
    read_line_2(str2, 6);
    printf("str2: %s\n", str2);
    while ((line = read_line(stdin)) != NULL) {
	printf("%s\n", line);
    }
    free_buffer();
}

