/*
f(i,j,h) : max #coins along the path (i,j) -> (m-1,n-1) with health = h
*/
class Solution {
public:
    int f(int i, int j, int h, vector<vector<int>> &coins, vector<vector<vector<int>>> &dp){
        // base case ::
        int m = coins.size(), n = coins[0].size();
        if(i == m-1 && j == n-1){
            if(coins[i][j] >= 0) return coins[i][j];
            if(h > 0) return 0;
            return coins[i][j];
        }
        if(i == m || j == n) return -1e9;

        // memo ::
        if(dp[i][j][h] != -1e9-5) return dp[i][j][h];
         
        // rln ::
        int not_fight = -1e9;
        int D = f(i+1,j,h,coins,dp), R = f(i,j+1,h,coins,dp);
        if( D != -1e9 ) not_fight = max(not_fight, coins[i][j] + D);
        if( R != -1e9 ) not_fight = max(not_fight, coins[i][j] + R);

        int fight = -1e9;
        if(h > 0){
            int d = f(i+1,j,h-1,coins,dp), r = f(i,j+1,h-1,coins,dp);
            fight = max(d,r);
        }

        return dp[i][j][h] = max(fight,not_fight); 
    }
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>> dp(coins.size(),vector<vector<int>>(coins[0].size(),vector<int>(3,-1e9-5)));
        return f(0,0,2,coins,dp);
    }
};