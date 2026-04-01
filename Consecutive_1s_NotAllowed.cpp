/* 
define state,
f(n,0) : #strings of len=n ending with 0
f(n,1) : #strings of len=n ending with 1

f(n,0) : f(n-1,0) + 0 : f(n-1,0) + f(n-1,1)
         f(n-1,1) + 0 

f(n,1) : f(n-1,0) + 1 : f(n-1,0)
*/
class Solution {
  public:
    int f(int n, int endsWith, vector<vector<int>> &dp){
        // base case ::
        if(n == 1) return 1;
        
        // memo ::
        if(dp[n][endsWith] != -1) return dp[n][endsWith];
        
        // rln ::
        return dp[n][endsWith] = f(n-1,0,dp) + (endsWith == 0)*f(n-1,1,dp);
    }
    
    int countStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(n,0,dp) + f(n,1,dp);
    }
};
