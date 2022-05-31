//
//  main.c
//  practice_2
//
//  Created by Azhun Zhu on 2021/11/3.
//

#include<stdio.h>

double calculateBonus(double money);
int main()
{
    double i, bonus;
    printf("你的净利润是(单位为：万)：\n");
    scanf("%lf",&i);
    bonus = calculateBonus(i);
    printf("提成为：bonus=%.2lf万\n",bonus);
   
}
double calculateBonus(double money) {
    if (money <= 10) {
        return money * 0.1;
    } else if(money <= 20) {
        return (money - 10) * 0.075 + calculateBonus(10);
    } else if(money <= 40) {
        return (money - 20) * 0.05 + calculateBonus(20);
    } else if(money <= 60) {
        return (money - 40) * 0.03 + calculateBonus(40);
    } else if(money <= 100) {
        return (money - 60) * 0.015 + calculateBonus(60);
    } else {
        return (money - 100) * 0.01 + calculateBonus(100);
    }
}
