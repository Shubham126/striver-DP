#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, -1, 1},
        {1, 1, 1}
    };

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){

            if(matrix[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }

            if(i == 0 and j == 0){
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(i > 0){
                up = dp[i-1][j];
            }
            if(j > 0){
                left = dp[i][j-1];
            }
            dp[i][j] = up + left;
        }
    }

    cout<<dp[rows-1][cols-1];

    return 0;
}