#include<bits/stdc++.h>
using namespace std;

int uniquePath(int iRow, int iCol, vector<vector<int>>&matrix, int rows, int cols, int sum){
    if( rows == iRow and cols == iCol){
        return 1;
    }

    if(rows < iRow || cols < iCol){
        return 0;
    }

    int up = 0;
    int left = 0;

    if(rows - 1 >= iRow){
        up = uniquePath(iRow, iCol, matrix, rows-1, cols, sum);
    }
    if(cols - 1 >= iCol){
        left = uniquePath(iRow, iCol, matrix, rows, cols-1, sum);
    }

    return up + left;
}

int main(){

    int rows = 4;
    int cols = 5;

    vector<vector<int>> matrix(rows, vector<int>(cols, 1));

    cout<<uniquePath(0, 0, matrix, rows-1, cols-1, 0);

    return 0;
}