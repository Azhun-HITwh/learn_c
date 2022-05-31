//
//  invcreate.c
//  memory_alloc
//
//  Created by Azhun Zhu on 2022/5/23.
//

#include "inventor.h"

#include <stdlib.h>
#include <stdio.h>

Invrec * create_subassy_record(int n_parts){
    
    Invrec *new_rec;
    
    new_rec = malloc(sizeof(Invrec));
    if (new_rec != NULL) {
        new_rec->info.subassy = malloc(sizeof(Subassyinfo));
        if (new_rec->info.subassy != NULL) {
            new_rec->info.subassy->part = malloc(n_parts * sizeof(struct SUBASSPART));
            if (new_rec->info.subassy->part != NULL) {
                new_rec->type = SUBASSY;
                new_rec->info.subassy->n_parts = n_parts;
                return new_rec;
            }
            free(new_rec->info.subassy);
        }
        free(new_rec);
    }
    return NULL;
}
