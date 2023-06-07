#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target){
    int start = 0, end = mat.size()-1;
    int mid = mat.size()/2;
    bool flag = false;
    while(start < end){
        if(!(mat[mid][0] <= target) || !(mat[mid][mat[0].size()-1] >= target)){
            if(mat[mid][0] > target){
                end = mid-1;
            }
            else start = mid+1;
            mid = (start + end)/2;
        }
        else {
            break;
        }
    }
    start = 0, end = mat[0].size()-1;
    int middle = (start + end)/2;
    while(start < end){
        if(mat[mid][middle] != target){
            if(mat[mid][middle] > target){
            end = middle-1;
            }
            else start = middle+1;
            middle = (start + end)/2;
        }
        else break;
    }
    if(mat[mid][middle] == target) return true;
    else return false;
    
}