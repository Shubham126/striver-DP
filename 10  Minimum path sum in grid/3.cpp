#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<vector<int>> matrix = {
        {2, 3, 4},
        {4, 3, 5},
        {1, 5, 6}
    };

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 1e9));
    dp[0][0] = matrix[0][0];

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            int left =  1e9;
            int up = 1e9;

            if(i == 0 && j == 0){
                continue;
            }

            if(i>0){
                up = matrix[i][j] + dp[i-1][j];
            }
            if(j>0){
                left = matrix[i][j] + dp[i][j-1];
            }

            dp[i][j] = min(left, up);
        }
    }

    cout<<dp[rows-1][cols-1];

    return 0;
}