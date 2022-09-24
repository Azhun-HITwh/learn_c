//
//  selftest.c
//  learnc
//
//  Created by Azhun Zhu on 2022/9/24.
//

#include "selftest.h"

#define MSG_ID 0x556
#define TWAI_STD_ID_MASK 0x7FF

int main(void){
    printf("msg_id: %x\n", MSG_ID<<21);
    printf("mask: %x\n", ~(TWAI_STD_ID_MASK << 21));
    return 0;
}
