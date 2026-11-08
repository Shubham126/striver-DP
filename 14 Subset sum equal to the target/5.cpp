// find if subsetSum sum exists using dp

#include<bits/stdc++.h>
using namespace std;

bool findIfExist(vector<int>&arr, int target, int n, vector<vector<int>> &dp){
    if(target == 0){
        return true;
    }
    if(n == 0){
        return (arr[0] == target);
    }

    if(dp[n][target] != -1){
        return dp[n][target];
    }

    bool pick = false;
    //pick
    if(arr[n] <= target){
        target -= arr[n];
        pick = findIfExist(arr, target, n-1, dp);
    }

    //notPick
    bool notPick = findIfExist(arr, target, n-1, dp);

    return dp[n][target] = pick | notPick;

}

int main(){

    vector<int> arr = {1, 2, 4, 6};
    int target = 4;

    vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));

    cout<<boolalpha<<findIfExist(arr, target, 3, dp);
}