#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {6, 4, 9, 8, 5};
    int n = arr.size();

    vector<int> dp(n, -1);

    dp[0] = arr[0];

    for(int i = 1; i<n; i++){
        int notPick = 0 + dp[i-1];
        int pick = -1;

        if(i>1){
            pick = arr[i] + dp[i-2];
        }

        dp[i] = max(pick, notPick);
    }

    cout<<dp[n-1]<<endl;

    return 0;
}