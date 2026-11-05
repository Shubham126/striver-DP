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

    vector<int>prev(cols, 1e9);

    for(int i = 0; i < rows; i++){
        vector<int> curr(cols, 1e9);
        for(int j = 0; j < cols; j++){

            if(i == 0 and j == 0){
                curr[j] = matrix[0][0];
                continue;
            }

            int up = 1e9;
            int left = 1e9;

            if(i > 0){
                up = prev[j]+matrix[i][j];
            }
            if(j > 0){
                left = curr[j-1]+matrix[i][j];
            }

            curr[j] = min(left , up);
        }
        prev = curr;
    }

    cout<<prev[cols-1];
    return 0;
}