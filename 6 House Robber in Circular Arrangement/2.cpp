#include<bits/stdc++.h>
using namespace std;

int robbing(vector<int>&arr, int n, vector<int> &dp){
    if(n == 0){
        return arr[0];
    }

    if(n<0){
        return 0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int pick = arr[n] + robbing(arr, n-2, dp);
    int notPick = 0 + robbing(arr, n-1, dp);

    return dp[n] = max(pick, notPick);
}

int robbingCircle(vector<int>&arr){

    int n = arr.size();
    if(n == 0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }

    vector<int> temp1;
    vector<int> temp2;

    for(int i = 0; i<=arr.size()-1; i++){
        if(i==0){
            temp1.push_back(arr[i]);
        }else if(i==(arr.size()-1)){
            temp2.push_back(arr[i]);
        }else{
            temp1.push_back(arr[i]);
            temp2.push_back(arr[i]);
        }
    }

    int sz1 = temp1.size();
    int sz2 = temp2.size();

    vector<int>dp1(sz1, -1);
    vector<int>dp2(sz2, -1);

    int first = robbing(temp1, sz1-1, dp1);
    int second = robbing(temp2, sz2-1, dp2);

    return max(first, second);
}

int main(){

    vector<int> arr = { 4, 7, 5, 7, 1, 9};
    cout<<robbingCircle(arr);

    return 0;
}