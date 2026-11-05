// now we are given a matrix with cell containig some value
// we are only allowed to move down and right
// find the minimum path sum required to reach from dest to src

#include<bits/stdc++.h>
using namespace std;

int findPath(vector<vector<int>> &matrix, int rows, int cols){

    if(rows < 0 or cols < 0){
        return INT_MAX;
    }
    if(rows == 0 and cols == 0){
        return matrix[0][0];
    }

    int up = INT_MAX;
    int left = INT_MAX;

    if(rows > 0){
        up = matrix[rows][cols] + findPath(matrix, rows-1, cols);
    }
    if(cols > 0){
        left = matrix[rows][cols] + findPath(matrix, rows, cols-1);
    }

    return min(up, left);
}

int main(){
    vector<vector<int>> matrix = {
        {2, 3, 4},
        {4, 3, 5},
        {1, 5, 6}
    };

    int row = matrix.size();
    int col = matrix[0].size();

    cout<< findPath(matrix, row-1, col-1);

    return 0;


}