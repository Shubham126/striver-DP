#include<bits/stdc++.h>
using namespace std;

int robbingCircle(vector<int> arr, int n, vector<int> &dp){
    
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];  
    }

    dp[0]=arr[0];

    for(int i = 1; i<n; i++){
        int notPick = 0 + dp[i-1];
        int pick = INT_MIN;

        if(i>1){
            pick = arr[i] + dp[i-2];
        }

        dp[i] = max(pick, notPick);
    }

    return dp[n-1];
}


int main(){

    vector<int> arr = {4, 7, 5, 7, 1, 9};
    int n = arr.size();

    int first, second;

    vector<int> temp1;
    vector<int> temp2;

    for(int i = 0; i<n; i++){
        if(i != 0){
            temp1.push_back(arr[i]);
        }
        if(i != n-1){
            temp2.push_back(arr[i]);
        }
    }

    int n1 = temp1.size();
    int n2 = temp2.size();

    vector<int> dp1(temp1.size(), -1);
    vector<int> dp2(temp2.size(), -1);

    first = robbingCircle(temp1, n1, dp1);
    second = robbingCircle(temp2, n2, dp2);

    cout<<max(first, second);

    return 0;
}