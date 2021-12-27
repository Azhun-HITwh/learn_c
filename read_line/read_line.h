#ifndef READ_LINE_H_INCLUDED
#define READ_LINE_H_INCLUDED

#include <stdio.h>

char *read_line(FILE *fp);
void free_buffer(void);
int read_line_2(char str[], int read_num);

#endif /* READ_LINE_H_INCLUDED */
