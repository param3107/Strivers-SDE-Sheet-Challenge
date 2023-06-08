//Moore's Voting Algorithm

#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n) {
	int count = 0, element;
    for(int i = 0; i < n; i++){
        if(!count){
            element = arr[i];
            count++;
        }
        else{
            if(element == arr[i]) count++;
            else count--;
        }
    }
    count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == element) count++;
    }
    if(count > n/2) return element;
    else return -1;
}