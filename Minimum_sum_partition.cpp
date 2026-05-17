/* Problem :
        Minimize the diff of sum of two subsets of a set 
*/

/*
        A + B = S
        A - B = A - (S-A) = 2A -S
        min {d} = abs(2A - S) 

        *Key Idea? Make it as close as possible to S/2
*/ 

class Solution {
  public:
    int f(int i, int S, vector<int> &arr, vector<vector<int>> &dp){
        // base case ::
        if(S < 0) return INT_MAX;
        if(i == arr.size()) return S;
        
        // memo ::
        if(dp[i][S] != -1) return dp[i][S];
        
        // recursive rln ::
        int not_pick = f(i+1,S,arr,dp);
        int pick = f(i+1,S-arr[i],arr,dp);
        
        return dp[i][S] = min(pick, not_pick);
    }
    int minDifference(vector<int>& arr) {
        int S = 0;
        for(int elem : arr) S += elem;
        vector<vector<int>> dp(arr.size(),vector<int>(S+1,-1));
        int A = (S/2) - f(0,S/2,arr,dp);
        return abs(2*A - S);
    }
};
