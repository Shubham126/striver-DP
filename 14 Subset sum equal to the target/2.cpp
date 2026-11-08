#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subset(vector<vector<int>>&ans, vector<int> &arr, vector<int> &ds, int sum, int n){

    if( n == arr.size()){
        int k = 0;
        for(int i = 0; i<ds.size(); i++){
            k+=ds[i];
        }
        if(k == sum){
                ans.push_back(ds);
        }
    }else{

        //pick
        ds.push_back(arr[n]);
        subset(ans, arr, ds, sum, n+1);

        //notPick
        ds.pop_back();
        subset(ans, arr, ds, sum, n+1);
    }

    return ans;
}

vector<vector<int>> findSubset(vector<int> &arr, int sum, int n){
    vector<vector<int>> ans;
    vector<int> ds;
    
    subset(ans, arr, ds, sum, n);
    return ans;
}

int main(){

    vector<int> arr = {1, 2, 3, 4};
    int sum = 4;

    vector<vector<int>> ans = findSubset(arr, sum, 0);

    for(auto it : ans){
        for(auto jit : it){
            cout<< jit <<" ";
        }cout<<endl;
    }
}