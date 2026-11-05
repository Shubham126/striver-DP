#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {4, 2, 5, 1, 9};
    int n = arr.size();

    int prev2 = 0;
    int prev1 = 0;
    int curr;

    for(int i = 0; i<n; i++){
        int notPick = 0 + prev1;
        int pick = -1;

        if(n>1){
            pick = arr[i] + prev2;
        }

        curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }

    cout<<prev1<<endl;
}