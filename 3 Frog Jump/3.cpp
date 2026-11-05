#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

int main(){

    vector<int> arr = {30, 10, 60, 40, 60, 50};

    vector<int> dp(arr.size(), INT_MAX);

    dp[0] = 0;

    for(int i = 1; i<arr.size(); i++){

        int left;
        int right = INT_MAX;
        
        left = dp[i-1] + abs(arr[i] - arr[i-1]);

        if(i > 1){
            right = dp[i-2] + abs(arr[i] - arr[i-2]);
        }

        dp[i] = min(left, right);
    }

    cout<<dp[arr.size()-1]<<endl;

    return 0;
}