//find Subsets

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>subsets(vector<vector<int>>&ans, vector<int> &arr, vector<int> &ds, int n){

    if(n == arr.size()){
        ans.push_back(ds);
    }else{
        //pick 
        ds.push_back(arr[n]);
        subsets(ans, arr, ds, n+1);

        //notpick
        ds.pop_back();
        subsets(ans, arr, ds, n+1);
    }

    return ans;
}

vector<vector<int>> findSubset(vector<int> &arr, int n){

    vector<vector<int>> ans;
    vector<int> ds;

    subsets(ans, arr, ds, n);

    return ans;

}

int main(){

    vector<int> arr = {1, 2, 3, 4};
    int target = 4;

    vector<vector<int>> ans = findSubset(arr, 0);

    for(auto it : ans){
        for(auto jit: it){
            cout<<jit<<" ";
        }cout<<endl;
    }
}