#include<bits/stdc++.h>
using namespace std;

int robbingLinear(vector<int> &arr){
    int n = arr.size();

    if(n==0){
        return 0;
    }
    if(n == 1){
        return arr[0];
    }

    int prev1 = 0;
    int prev2 = 0;
    int curr;

    for(int i = 0; i<n; i++){
        int notPick = 0 + prev1;
        int pick = arr[i] + prev2;

        curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int robbingCircle(vector<int> &arr){

    int n = arr.size();

    if(n == 0){
        return 0;
    }
    if(n == 1){
        return arr[0];
    }

    vector<int> temp1;
    vector<int> temp2;

    for(int i = 0; i<n; i++){
        if(i != 0){
            temp2.push_back(arr[i]);
        }
        if(i != n-1){
            temp1.push_back(arr[i]);
        }
    }

    return max(robbingLinear(temp1), robbingLinear(temp2));
}

int main(){

    vector<int> arr = {4, 7, 5, 7, 8, 9};

    cout<<robbingCircle(arr);

    return 0;
}