// Ninjas training using Recursion

#include<bits/stdc++.h>
using namespace std;

int findPoints(vector<vector<int>> &points, int days, int last){

    if(days == 0){
        int maxi = 0;

        for(int task = 0; task<3; task++){
            if(task != last){
                maxi = max(maxi, points[0][task]);
            }
        }

        return maxi;
    }

    int maxi = 0;

    for(int task = 0; task<3; task++){
        if(task != last){
            int point = points[days][task] + findPoints(points, days-1, task);
            maxi = max(maxi, point);
        }
    }

    return maxi;
}

int main(){

    vector<vector<int>> points = {
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6},
        {8, 3, 7}
    };

    // cout<<points[1][1];

    int days = points.size();
    // int tasks = points[0].size();

    cout<<findPoints(points, days-1, 3);

    return 0;
}