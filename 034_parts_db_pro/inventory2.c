//
//  main.c
//  parts_db_pro
//
//  Created by Azhun Zhu on 2022/1/8.
//

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 20

typedef struct part{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part* next;
}part;


void menu(void);
part* find_part(part* head, int number);
void insert(part* head);
void search(part* head);
void update(part* head);
void print(part* head);

int main(void){
    
    char code = 'a';
    part* head = (part*)malloc(sizeof(part));
    head->next = NULL;
    
    if (head == NULL) {
        printf("Database establish failed\n");
        exit(EXIT_SUCCESS);
    }
    
    menu();
    for(;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);
        switch (code) {
            case 'i':
                insert(head);
                break;
            case 's':
                search(head);
                break;
            case 'u':
                update(head);
                break;
            case 'p':
                print(head);
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code.\n");
                break;
        }
    }
    
    return 0;
}

void menu(void){
    
    printf("                        ==================================\n");
    printf("                        *                                *\n");
    printf("                        *            i:  insert          *\n");
    printf("                        *            s:  search          *\n");
    printf("                        *            u:  undate          *\n");
    printf("                        *            p:  print           *\n");
    printf("                        *            q:  quit            *\n");
    printf("                        *                                *\n");
    printf("                        ==================================\n");
}

part* find_part(part* head, int number) {

    part* cur;

    for (cur = head->next; cur != NULL && cur->number < number;
        cur = cur->next)
        ;
    
    if (cur->number == number)
        return cur;
    else
        return NULL;
}

void insert(part* head){
    int part_number;
    part* cur, * prev, * new_part;
    
    printf("Enter part number: ");
    scanf("%d", &part_number);
    
    for (cur = head->next, prev = NULL; cur != NULL && cur->number < part_number;
         prev = cur, cur = cur->next) {
        ;
    }
    
    if (cur != NULL && cur->number == part_number) {
        printf("Part already exists.\n");
        return ;
    }
    
    new_part = (part*)malloc(sizeof(part));
    
    if (new_part == NULL){
        printf("Database is full; can't add more parts.\n");
        return ;
    }
    
    new_part->number = part_number;
    printf("Enter part name: ");
    read_line(new_part->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_part->on_hand);
    
    new_part->next = cur;
    
    if (prev == NULL)
        head->next = new_part;
    else
        prev->next = new_part;
}

void search(part* head){
    
    int number;
    part* trg;
    
    printf("Enter part number: ");
    scanf("%d", &number);
    
    trg = find_part(head, number);
    
    if (trg == NULL) {
        printf("Part not found.\n");
        return;
    }
    
    printf("Part name: %s\n", trg->name);
    printf("Quantity on hand: %d\n", trg->on_hand);
    
}

void update(part* head){
    
    int num, change;
    part* trg;
    
    printf("Enter part number: ");
    scanf("%d", &num);
    
    trg = find_part(head, num);
    
    if (trg == NULL) {
        printf("Part not found.\n");
        return ;
    }
    printf("Enter change in quantity on hand(- means minus): ");
    scanf("%d", &change);
    trg += change;
    
}

void print(part* head){
    
    printf("Part Number      Part Name      Quantity on Hand\n");
    for (part* cur = head->next; cur != NULL; cur = cur->next) {
        printf("%6d%20s%15d\n", cur->number, cur->name, cur->on_hand);
    }
}
