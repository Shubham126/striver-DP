#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &triangle, vector<vector<int>> &dp, int n, int rows, int cols){
    if(rows == n){
        return triangle[rows][cols];
    }

    if(dp[rows][cols] != -1){
        return dp[rows][cols];
    }

    int down = triangle[rows][cols] + minPathSum(triangle, dp, n, rows+1, cols);
    int diagonal = triangle[rows][cols] + minPathSum(triangle, dp, n, rows+1, cols+1);

    return dp[rows][cols] = min(down, diagonal);


}

int findMinPath(vector<vector<int>> &triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return minPathSum(triangle, dp, n, 0, 0);
}

int main(){

        vector<vector<int>> triangle{
        {1},
        {2, 3},
        {4, 5, 6},
        {7, 8, 9, 10}
    };

    cout<< findMinPath(triangle, 3);

    return 0;

}