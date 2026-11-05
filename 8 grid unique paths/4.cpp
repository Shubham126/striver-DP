#include<bits/stdc++.h>
using namespace std;

int main(){

    int rows = 4;
    int cols = 5;

    vector<vector<int>>matrix(rows, vector<int>(cols, 1));
    
    vector<int> prev(cols, 0);
    vector<int> curr(cols, 0);

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(i == 0 or j == 0){
                curr[j] = 1;
            }else{
                curr[j] = curr[j-1] + prev[j];
            }
        }
        prev = curr;
    }

    cout<<prev[cols-1]<<endl;
    
    return 0;
    
}