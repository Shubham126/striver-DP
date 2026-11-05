#include<bits/stdc++.h>
using namespace std;

int robbing(vector<int> &arr, int n){
    if(n == 0){
        return arr[0];
    }

    if(n<0){
        return 0;
    }

    int pick = arr[n] + robbing(arr, n-2);
    int notPick = 0 + robbing(arr, n-1);

    return max(pick, notPick);
}

int robbingCircle(vector<int>&arr, int n){
    if(n == 0){
        return arr[0];
    }

    vector<int> temp1;
    vector<int> temp2;

    for(int i = 0; i<=n; i++){
        if(i == 0){
            temp1.push_back(arr[i]);
        }else if(i == n){
            temp2.push_back(arr[i]);
        }else{
            temp1.push_back(arr[i]);
            temp2.push_back(arr[i]);
        }
    }

    int first = robbing(temp1, n-1);
    int second = robbing(temp2, n-1);

    return max(first, second);

}

int main(){

    vector<int> arr = {4, 7, 5, 7, 1, 9};
    int n = arr.size();

    cout<<robbingCircle(arr, n-1);

    return 0;
}