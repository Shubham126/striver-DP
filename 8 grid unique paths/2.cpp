#include<bits/stdc++.h>
using namespace std;

int findPath(int rows, int cols, vector<vector<int>>&matrix, vector<vector<int>> &dp){

    if(rows == 0 and cols == 0){
        return 1;
    }

    if(rows < 0 or cols < 0){
        return 0;
    }

    if(dp[rows][cols] != -1){
        return dp[rows][cols];
    }

    int up = 0;
    int left = 0;

    if(rows -1 >= 0){
        up = findPath(rows-1, cols, matrix, dp);
    }
    if(cols -1 >= 0){
        left = findPath(rows, cols-1, matrix, dp);
    }

    return dp[rows][cols] = up + left;
}

int main(){

    int rows = 4;
    int cols = 5;

    vector<vector<int>> matrix(rows, vector<int> (cols, 1));
    vector<vector<int>> dp(rows, vector<int> (cols, -1));
    cout<<findPath(rows - 1 , cols - 1 , matrix, dp);

    return 0;
}