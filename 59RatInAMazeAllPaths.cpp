#include <bits/stdc++.h>
using namespace std;

void insertConfig(vector<vector<int>> &ans, vector<pair<int, int>> &path, int n){
    vector<int> config(n*n);
    // fill_n(config.begin(), n*n, 0);
    for(int i = 0; i < path.size(); i++){
        config[n*path[i].first + path[i].second] = 1;
    }
    ans.push_back(config);
    return;
}

bool inPath(int x, int y, vector<pair<int, int>> &path){
    for(int i = path.size() - 1; i >= 0; i--){
        if(x == path[i].first && y == path[i].second) return true;
    }
    return false;
}

void countPaths(int x, int y, int n, vector<pair<int, int>> &path, vector<vector<int>> &maze, vector<vector<int>> &ans){
    if(x == n-1 && y == n-1){
        path.push_back({x, y});
        insertConfig(ans, path, n);
        path.pop_back();
        return;
    }
    else if (inPath(x, y, path)) return;
    else if (maze[x][y] == 0) return;
    else{
        path.push_back({x, y});
        if(x < n-1) countPaths(x+1, y, n, path, maze, ans);
        if(x > 0) countPaths(x-1, y, n, path, maze, ans);
        if(y < n-1) countPaths(x, y+1, n, path, maze, ans);
        if(y > 0) countPaths(x, y-1, n, path, maze, ans);
        path.pop_back();
        return;
    }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans;
    vector<pair<int, int>> path = {};
    countPaths(0, 0, n, path, maze, ans);
    return ans;
}