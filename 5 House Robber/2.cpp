#include<bits/stdc++.h>
using namespace std;

int houseRobber(vector<int> &arr, int n, vector<int> &dp){
    if(n==0){
        return arr[0];
    }
    if(n<0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int pick = arr[n] + houseRobber(arr, n-2, dp);
    int notPick = 0 + houseRobber(arr, n-1, dp);

    return dp[n] = max(pick, notPick);
}

int main(){
    vector<int> arr = {1, 2, 9, 8, 4};
    int n = arr.size();

    vector<int> dp(n, -1);

    cout<<houseRobber(arr, n-1, dp);

    return 0;
}