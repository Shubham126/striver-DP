//return true or false if a subsequence exist

#include<bits/stdc++.h>
using namespace std;

bool findIfSubsetExist(vector<int> &arr, int n, int target){

    if(n == 0){
        if(target == 0){
            return true;
        }else{
            return false;
        }
    }

    bool pick = false;

    // pick
    if(arr[n] <= target){
        target -= arr[n];
        pick = findIfSubsetExist(arr, n-1, target);
    }

    // not Pick
    bool notPick = findIfSubsetExist(arr, n-1, target);

    return pick | notPick;


}

int main(){

    vector<int> arr = {1, 2, 4, 6};
    int target = 4;

    cout<<boolalpha;
    cout<<findIfSubsetExist(arr, 3, target)<<endl;

    return 0;
}