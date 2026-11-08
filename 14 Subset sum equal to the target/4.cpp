//find if subset sum equal to a given integer k exists

#include<bits/stdc++.h>
using namespace std;

bool findIfSubsetExist(vector<int> &arr, int n, int target){

    if(target == 0 ){
        return true;
    }
    if(n == 0){
        return (arr[0] == target);
    }

    bool Nottake = findIfSubsetExist(arr, n-1, target);

    bool take = false;
    if(arr[n] <= target){
        take = findIfSubsetExist(arr, n-1, target-arr[n]);
    }

    return take | Nottake;
}

int main(){

    vector<int> arr = {1, 2, 5, 6};

    int target = 4;
    int n = 3;

    cout<<boolalpha<<findIfSubsetExist(arr, n, target)<<endl;

    return 0;
}