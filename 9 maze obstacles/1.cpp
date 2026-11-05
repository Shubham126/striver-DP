// Unique path 2
// in this we will have a maze with some values as -1
// the -1 cells can't be accesed and it's a dead path

#include<bits/stdc++.h>
using namespace std;

int findPath(vector<vector<int>>&matrix, int rows, int cols){

    if(rows < 0 or cols < 0){
        return 0;
    }
    if(matrix[rows][cols] == -1){
        return 0;
    }
    if(rows == 0 and cols == 0){
        return 1;
    }

    int left = 0;
    int up = 0;

    if( rows > 0){
        up = findPath(matrix, rows-1, cols);
    }
    if(cols > 0){
        left = findPath(matrix, rows, cols-1);
    }

    return left + up;
}

int main(){

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, -1, 1},
        {1, 1, 1}
    };

    int rows = matrix.size();
    int cols = matrix[0].size();

    cout<<findPath(matrix, rows-1, cols-1);

    return 0;
}