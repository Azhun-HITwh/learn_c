//
//  main.c
//  parts_db
//
//  Created by Azhun Zhu on 2022/1/7.
//

#include <stdio.h>
#include "read_line.h"

#define NAME_LEN 20
#define MAX_PARTS 100

struct part{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
}inventory[MAX_PARTS];

int num_parts = 0;

void menu();
int find_part(int number);
void insert();
void search();
void update();
void print();

int main(void){
    
    char code = 'a';
    
    menu();
    
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') {
            ;
        }
        switch (code) {
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            case 'q':
                return 0;
            default:
                print("Illegal code.\n");
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
    printf("                        *            u:  update          *\n");
    printf("                        *            p:  print           *\n");
    printf("                        *            q:  quit            *\n");
    printf("                        *                                *\n");
    printf("                        ==================================\n");

}

int find_part(int number){
    
    int i;
    
    for (i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            return i;
        }
    }
    return -1;
}

void insert(void){
    
    int part_number;
    
    if (num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }
    
    printf("Enter part number: ");
    scanf("%d", &part_number);
    
    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }
    
    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}

void search(){
    
    int index, number_part;
    printf("Enter part number: ");
    scanf("%d", &number_part);
    
    index = find_part(number_part);
    
    if (index == -1) {
        printf("Part not found.\n");
                return;
    }
    
    printf("Part name: %s\n", inventory[index].name);
    printf("Quantity on hand: %d\n", inventory[index].on_hand);
}

void update(){
    int number, index, change;
    
    printf("Enter part number: ");
    scanf("%d", &number);
    
    index = find_part(number);
    
    if (index == -1){
        printf("Part not found.\n");
        return;
    }
    
    printf("Enter change in quantity on hand(- means minus): ");
    scanf("%d", &change);
    inventory[index].on_hand += change;
}

void print(){
    int i;
    
    printf("Part Number      Part Name      Quantity on Hand\n");
    for (i = 0; i < num_parts; i++) {
        printf("%6d%20s%15d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }
    return;
}
