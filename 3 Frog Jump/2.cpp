#include<bits/stdc++.h>
using namespace std;

int frogJump(vector<int>&arr, int n, vector<int>&cost){
    if(n==0){
        cost[0] == 0;
        return 0;
    }
    
    int left;
    int right = INT_MAX;

    if(cost[n] != -1){
        return cost[n];
    }

    left = frogJump(arr, n-1, cost) + abs(arr[n] - arr[n-1]);

    if(n>1){
       
        right = frogJump(arr, n-2, cost) + abs(arr[n] - arr[n-2]);
        
    }

    return cost[n] = min(left, right);
}

int main(){

    vector<int> arr = {10, 30, 60, 10, 60, 50};

    vector<int> cost(arr.size(), -1);

    cout<<frogJump(arr, arr.size()-1, cost);

    return 0;
}