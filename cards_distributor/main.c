//
//  main.c
//  cards_distributor
//
//  Created by Azhun Zhu on 2021/12/26.
//

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_SUIT 4
#define NUM_RANK 13

int main(int argc, const char * argv[]) {
    
    int suit, rank, num_cards;
    
    const char suite[] = {'H', 'D', 'C', 'S'};
    const char rank_card[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
    bool in_hand[NUM_SUIT][NUM_RANK] = {false};
    
    srand((unsigned)time(NULL));
    
    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);
    
    printf("Your card(s): ");
    while (num_cards > 0) {
        suit = rand() % NUM_SUIT;
        rank = rand() % NUM_RANK;
        
        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;
            printf("%c%c  ", suite[suit], rank_card[rank]);
        }
    }
    printf("\n");
    
    
    return 0;
}
