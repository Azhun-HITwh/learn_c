//
//  queue.h
//  queue
//
//  Created by Azhun Zhu on 2022/5/31.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_TYPE int

void create_queue(size_t size);
void destory_queue(void);
void insert(QUEUE_TYPE value);
void delete(void);
QUEUE_TYPE first(void);
int is_empty(void);
int is_full(void);
void print_queue(void);

#endif /* queue_h */
