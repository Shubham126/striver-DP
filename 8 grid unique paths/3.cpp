#include<bits/stdc++.h>
using namespace std;

int main(){

    int rows = 4;
    int cols = 5;

    vector<vector<int>> matrix(rows, vector<int> (cols, 1));

    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    dp[0][0] = 1;


    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(i == 0 or j == 0){
                dp[i][j] = 1;
            }else{
                int left = dp[i-1][j];
                int up = dp[i][j-1];

                dp[i][j] = left + up;
            }
        }
    }

    cout<<dp[rows-1][cols-1];

    return 0;
}