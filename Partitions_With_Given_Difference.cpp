/*
Considering A > B,

A + B = Sum
A - B = diff

A = (Sum+diff)/2

Now, how many subsets have sum = (Sum + Diff)/2 ?

lets's define state,

f(n,sum) = f(n-1,sum) + f(n-1,sum-arr[n])
*/

class Solution {
  public:
    int f(int n, int sum, vector<vector<int>> &dp, vector<int> &arr){
        // base case ::
        if(sum < 0) return 0;
        if(n < 0) return sum == 0;
        
        // memo ::
        if(dp[n][sum] != -1) return dp[n][sum];
        
        // rln ::
        return dp[n][sum] = f(n-1,sum,dp,arr) + f(n-1,sum-arr[n],dp,arr);
    }
    
    int countPartitions(vector<int>& arr, int diff) {
       int sum = 0;
       for(int elem : arr) sum += elem;
       sum = sum + diff;
       
       if(sum&1) return 0;
       sum = sum/2;
       
       vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
       return f(arr.size()-1,sum,dp,arr);
       
    }
};