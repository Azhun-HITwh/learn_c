//
//  main.c
//  guess_number
//
//  Created by Azhun Zhu on 2021/12/28.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

// global parameter
int secret_num;

void generate_secret_num(void);
void read_guess(void);

int main(int argc, const char * argv[]) {
    char command;
    printf("Guess the secret number between 1 and 100.\n");
    do {
        generate_secret_num();
        printf("A new number has been chosen.\n");
        read_guess();
        printf("Play again?(Y/N)");
        scanf(" %c", &command);
        printf("\n");
    } while ((command == 'Y') || (command == 'y'));
    return 0;
}

void generate_secret_num(){
    srand((unsigned)time(NULL));
    secret_num = rand() % MAX_NUM + 1;
}

void read_guess(){
    int guess, count = 0;
    
    for(;;){
        printf("Enter guess: ");
        scanf("%d", &guess);
        count++;
        if (guess > secret_num) {
            printf("Too high; try again\n");
        }
        else if (guess < secret_num){
            printf("Too low; try again.\n");
        }
        else{
            printf("You won in %d guesses!\n\n", count);
            return;
        }
    }
}
