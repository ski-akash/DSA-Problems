/* Problem:-
            f(start) : check if we can reach 0 valued index from index = {start} 
            possible movements : {index - arr[index]} <---- index ----> {index + arr[index]}
*/

/* Note:-
            keep track of visited indexes in visited array cz we can go in both directions..
            so we don't end up asking the same query again!!
*/


class Solution {
public:
    bool f(int i, vector<int> &a, vector<int> &dp, vector<int> &vis){
        // base case ::
        if(i < 0 || i >= a.size()) return false;
        if(a[i] == 0) return true;
        if(vis[i]) return false;

        // memo ::
        if(dp[i] != -1) return dp[i];

        // recursive rln ::
        vis[i] = 1;
        return dp[i] = false | f(i+a[i],a,dp,vis) | f(i-a[i],a,dp,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(),-1), vis(arr.size(),0);
        return f(start,arr,dp,vis);
    }
};