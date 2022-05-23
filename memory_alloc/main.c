//
//  main.c
//  memory_alloc
//
//  Created by Azhun Zhu on 2022/5/23.
//

#include <stdio.h>
#include <stdlib.h>

#include "inventor.h"

int main(int argc, const char * argv[]) {
    
    Invrec *ecu = create_subassy_record(2);
    printf("type:%d\n", ecu->type);
    
    return 0;
}
