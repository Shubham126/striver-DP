#include<bits/stdc++.h>
using namespace std;

int robbingLinear(vector<int>&arr, int start, int end){

    int prev1 = 0;
    int prev2 = 0;
    int curr;

    for(int i = start; i<end; i++){
        int pick = arr[i] + prev2;
        int notPick = 0 + prev1;

        curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }


    return prev1;
}

int robbingCircle(vector<int> &arr){

    int n = arr.size();
    
    return max(robbingLinear(arr, 0, n-1), robbingLinear(arr, 1, n));
}

int main(){

    vector<int> arr = {4, 7, 8, 7, 2, 9};

    cout<<robbingCircle(arr);

    return 0;
}