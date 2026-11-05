#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>&triangle, int rows, int cols, int n){

    if(rows == n){
        return triangle[rows][cols];
    }

    int down = triangle[rows][cols] + minPathSum(triangle, rows+1, cols, n);
    int diagonalDown = triangle[rows][cols] + minPathSum(triangle, rows+1, cols+1, n);

    return min(down, diagonalDown);

}

int findMinPath(vector<vector<int>> triangle, int n){
    return minPathSum(triangle, 0, 0, n);
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