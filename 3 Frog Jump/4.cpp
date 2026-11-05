#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {30, 10, 60, 40, 60, 40};

    int prev = 0;
    int prev2 = 0;
    int curr;

    for(int i = 1; i< arr.size(); i++){

        int left = prev + abs(arr[i] - arr[i-1]);
        int right = INT_MAX;

        if(i>1){
            right = prev2 + abs(arr[i] - arr[i-2]);
        }

        curr = min(left, right);
        prev2 = prev;
        prev = curr;

    }

    cout<< prev;

    return 0;
}