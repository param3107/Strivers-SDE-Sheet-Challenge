#include <bits/stdc++.h> 
using namespace std;

int findMinimumCoins(int amount){
    int denom[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int i = 8;
    int coins = 0;
    while(amount){
        if(denom[i] > amount) i--;
        else{
            coins += amount/denom[i];
            amount = amount%denom[i];
        }
    }
    return coins;
}
