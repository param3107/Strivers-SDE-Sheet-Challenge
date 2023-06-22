#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n){
    sort(at, at+n);
    sort(dt, dt+n);
    int platforms = 1, departed = 0;
    for(int i = 0; i < n; i++){
        if(at[i] <= dt[departed]) platforms++;
        else departed++;
    }
    return departed;
}