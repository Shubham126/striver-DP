#include<bits/stdc++.h>
using namespace std;

int findPath(vector<vector<int>>&matrix, int rows, int cols, vector<vector<int>> &dp){

    if(rows < 0 or cols < 0){
        return 0;
    }
    if(matrix[rows][cols] == -1){
        return 0;
    }
    if(rows == 0 and cols == 0){
        return 1;
    }

    if(dp[rows][cols] != -1){
        return dp[rows][cols];
    }

    int up = 0;
    int left = 0;

    if(rows > 0){
        up = findPath(matrix, rows-1, cols, dp);
    }
    if(cols > 0){
        left = findPath(matrix, rows, cols-1, dp);
    }
    
    return dp[rows][cols] = (up + left);
}

int main(){

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, -1, 1},
        {1, 1, 1}
    };

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    cout<<findPath(matrix, rows-1, cols-1, dp);

    return 0;
}