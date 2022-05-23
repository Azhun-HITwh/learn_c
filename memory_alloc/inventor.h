//
//  inventor.h
//  memory_alloc
//
//  Created by Azhun Zhu on 2022/5/23.
//

#ifndef inventor_h
#define inventor_h

#include <stdio.h>

typedef struct {
    int cost;
    int supplier;
} Partinfo;

typedef struct {
    int n_parts;
    struct SUBASSPART {
        char partno[10];
        short quan;
    } *part;
} Subassyinfo;

typedef struct {
    char partno[10];
    int quan;
    enum {PART, SUBASSY} type;
    union {
        Partinfo *part;
        Subassyinfo *subassy;
    } info;
} Invrec;

Invrec * create_subassy_record(int n_parts);
void discard_inventory_record(Invrec *record);

#endif /* inventor_h */
