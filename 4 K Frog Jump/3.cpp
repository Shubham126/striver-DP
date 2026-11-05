#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {30, 10, 60, 10, 60, 40};

    int n = arr.size();

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    int k = 3;

    for(int i = 0; i<n; i++){

        for(int j = 1; j<=k; j++){
            
            if(i-j >= 0){
                int jump = dp[i-j] + abs(arr[i] - arr[i-j]);
                dp[i] = min(dp[i], jump);
            }
        }
    }

    cout<<dp[n-1];

    return 0;
}