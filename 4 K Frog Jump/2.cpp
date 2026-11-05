//Kth frog Jump

#include<bits/stdc++.h>
using namespace std;

int frogJump(vector<int>&arr, vector<int> &dp, int n, int k){

    if(n == 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int mini = INT_MAX;

    for(int i = 1; i<=k; i++){
        if(n - i >= 0){
            int jump = frogJump(arr, dp, n-i, k) + abs(arr[n] - arr[n-i]);
            mini = min(mini, jump);
        }
    }

    return dp[n] = mini;
    
}

int main(){

    vector<int> arr = {30, 10, 60, 10, 60, 40};
    int k = 3;

    vector<int> dp(arr.size(), -1);

    cout<< frogJump(arr, dp, arr.size()-1, k);

    return 0;
}