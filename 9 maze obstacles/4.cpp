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

    vector<int> prev(cols, 0);

    for(int i = 0; i < rows; i++){
        
        vector<int> curr(cols, 0);

        for(int j = 0; j<cols; j++){
            
            if(matrix[i][j] == -1 ){
                curr[j] = 0;
                continue;
            }

            if(i == 0 and j == 0){
                curr[j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(i > 0){
                up = prev[j];
            }
            if(j > 0){
                left = curr[j-1];
            }

            curr[j] = up + left;
        }
        prev = curr;
    }

    cout<<prev[cols-1];
    return 0;
}