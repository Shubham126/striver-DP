// Kth frog jump

#include<bits/stdc++.h>
using namespace std;

int KFrogJump(vector<int> &arr, int n, int k){

    if(n==0){
        return 0;
    }

    int mini = INT_MAX;

    for(int i = 1; i<=k; i++){
        if(n - i >= 0){
            int jump = KFrogJump(arr, n-i, k) + abs(arr[n] - arr[n-i]);
            mini = min(mini, jump);
        }
    }

    return mini;
}

int main(){

    vector<int> arr = {30, 10, 60, 10, 60, 40};

    int n = arr.size();

    int k = 3;

    cout<<KFrogJump(arr, n-1, k);

    return 0;
}