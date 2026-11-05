//Ninjas training using dp and memoization

#include<bits/stdc++.h>
using namespace std;

int countPoints(vector<vector<int>> &points, int days, int last, vector<vector<int>> &dp){

    if(days == 0){
        int maxi = 0;

        for(int tasks = 0; tasks<3; tasks++){
            if(tasks != last){
                maxi = max(maxi, points[0][tasks]);
            }
        }

        return maxi;
    }

    if(dp[days][last] != -1){
        return dp[days][last];
    }
    

    int maxi = 0;

    for(int tasks = 0; tasks<3; tasks++){
        if(tasks != last){
            int point = points[days][tasks] + countPoints(points, days-1, tasks, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[days][last] = maxi;
}

int main(){

    vector<vector<int>> points = {
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6},
        {8, 3, 7}
    };

    int days = points.size();

    vector<vector<int>> dp(days, vector<int>(4, -1));

    cout<<countPoints(points, days-1, 3, dp);

    return 0;
}