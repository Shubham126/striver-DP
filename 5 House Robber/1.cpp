// Normal recursive solution

#include<bits/stdc++.h>
using namespace std;

int houseRobber(vector<int>&arr, int n){

    if(n == 0){
        return arr[0];
    }
    if(n<0){
        return 0;
    }

    int first = arr[n] + houseRobber(arr, n-2);
    int second = 0 + houseRobber(arr, n-1);

    return max(first, second);
}

int main(){

    vector<int>arr = {1, 2, 8, 9, 4, 4};
    int n = 6;

    cout<<houseRobber(arr, n-1);

    return 0;
}