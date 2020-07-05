//
// main.cpp
//
// Mariam Joan
// Project 2
// Program to print dollar and coin denominations from user money amount input
// Due: July 5, 2020


#include <iostream>

int main(int argc, const char * argv[]) {

    // dollar and coin denomination variables
    int num100s;
    int num20s;
    int num10s;
    int num5s;
    int num1s;
    
    int coin25s;
    int coin10s;
    int coin5s;
    int coin1s;
    
    // user input amount variables
    float money;
    int dollars;
    int coins;
    
    // prompt for money amount
    printf("Enter amount: ");
    scanf("%f", &money);
    
    // assign user money amount to dollars
    dollars = (int)money;
    
    // assign user money amount to coins
    coins = (int)(money * 100) % 100;
    
    // dollar denomination amount assignments
    num100s = dollars/100;
    dollars %= 100;
    
    num20s = dollars/20;
    dollars %= 20;
    
    num10s = dollars/10;
    dollars %= 10;
    
    num5s = dollars/5;
    dollars %= 5;
    
    num1s = dollars/1;
    dollars %= 1;
    
    // coin denomination amount assignments
    coin25s = coins/25;
    coins %= 25;
    
    coin10s = coins/10;
    coins %= 10;
    
    coin5s = coins/5;
    coins %= 5;
    
    coin1s = coins/1;
    coins %= 1;
    
    // print out user input dollar and coin assignments
    printf("Mariam Joan - Project 2\n\n");    
    printf("Amount of money: %6.2f\n\n", money);
    
    printf("Dollar denominations: \n\n");
    printf("Number of dollars: %d\n", int(money));
    printf("Number of $100.00s: %d\n", num100s);
    printf("Number of $20.00s: %d\n", num20s);
    printf("Number of $10.00s: %d\n", num10s);
    printf("Number of $5.00s: %d\n", num5s);
    printf("Number of $1.00s: %d\n", num1s);
    printf("\n");

    // expanded program to read coins denominations
    printf("Coin denominations: \n\n");
    printf("Number of 0.25s: %d\n", coin25s);
    printf("Number of 0.10s: %d\n", coin10s);
    printf("Number of 0.05s: %d\n", coin5s);
    printf("Number of 0.01s: %d\n", coin1s);
    printf("\n");
    
    printf("Mariam Joan - End of Project 2\n\n");
}
