#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {30, 10, 60, 10, 40};
    int n = arr.size();

    int k = 3;

    vector<int> dp(k, 0);

    for(int i = 1; i<n; i++){
        int curr = INT_MAX;
        for(int j = 1; j<=k; j++){
            if(i-j >= 0){
                int jump = dp[(i-j) % k] + abs(arr[i] - arr[i-j]);
                curr = min(curr, jump);
            }
        }
        dp[i % k] = curr;
    }

    cout<<dp[(n-1)%k];

    return 0;
}