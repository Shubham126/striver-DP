#include<bits/stdc++.h>
using namespace std;

int findPath(vector<vector<int>>&matrix, int rows, int cols, vector<vector<int>>&dp){
    if(rows < 0 or cols < 0){
        return INT_MAX;
    }
    if(rows == 0 and cols == 0){
        return matrix[0][0];
    }

    if(dp[rows][cols] != -1){
        return dp[rows][cols];
    }

    int up = INT_MAX;
    int left = INT_MAX;

    if(rows>0){
        up = matrix[rows][cols] + findPath(matrix, rows-1, cols, dp);
    }
    if(cols > 0){
        left = matrix[rows][cols] + findPath(matrix, rows, cols-1, dp);
    }

    return dp[rows][cols] = min(up, left);
}

int main(){

    vector<vector<int>> matrix = {
        {2, 3, 4},
        {4, 3, 5},
        {1, 5, 6}
    };

    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> dp(row, vector<int>(col, -1));

    cout<< findPath(matrix, row-1, col-1, dp);
}