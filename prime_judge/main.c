//
//  main.c
//  prime_judge
//
//  Created by Azhun Zhu on 2021/12/26.
//

#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n){
    
    if (n <= 1) {
        return false;
    }
    
    for (int devisor = 2; devisor*devisor <= n; devisor++) {
        if (n % devisor == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (is_prime(n)) {
        printf("Prime\n");
    }
    else{
        printf("Not Prime\n");
    }
    return 0;
}
