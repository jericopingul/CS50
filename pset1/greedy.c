#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;

    do {
    printf("O hai! How much change is owed?\n");
    change = GetFloat();
    } while (change < 0);
    
    // convert to integer (total in cents)
    int intChange = (int) (round(change*100));
    
    int quarter = 25, dime = 10, nickel = 5, penny = 1;   
    int nCoins = 0; // number of coins
    
    // count quarters
    while(intChange >= quarter) {
        intChange -= quarter;
        nCoins++;
    }
    
    // count dimes
    while(intChange >= dime) {
        intChange -= dime;
        nCoins++;
    }
    
    // count nckels
    while(intChange >= nickel) {
        intChange -= nickel;
        nCoins++;
    }
    
    // count pennies
    while(intChange >= penny) {
        intChange -= penny;
        nCoins++;
    }
    
    printf("%d\n", nCoins);
}
