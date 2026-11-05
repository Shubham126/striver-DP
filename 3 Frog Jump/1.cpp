//Frog Jump

// if my frog reached the nth step

// it must have reached either from n-1 step after doing a jump of 1
// or from n-1 step after doing a jump of 2

// what is left and right here?? 
// the funtion calculates the minimum of all differences
// left store the left minimum
// adding the abs(n - n-1) helps us get the sum of all the stairs from the 0th step to the n-1 step and abs added the final step

#include<bits/stdc++.h>
using namespace std;

int frogJump(vector<int> &arr, int n){

    if(n == 0){
        return 0;
    }
    int left = frogJump(arr, n-1) + abs(arr[n] - arr[n-1]);

    int right = INT_MAX;
    if(n>1){
        right = frogJump(arr, n-2) + abs(arr[n] - arr[n-2]);
    }

    return min(left, right);
}

int main(){

    vector<int> arr = {10, 30, 20, 10};

    cout<< frogJump(arr, arr.size()-1);

    return 0;
}