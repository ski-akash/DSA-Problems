/* Problem : 
        Find the smallest positive integer such that it can't be formed by sum of subsets of array
*/ 

class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        int R = 0;
        sort(arr.begin(),arr.end());
        for(int x : arr){
            if(x <= R+1) R += x;
            else return R+1;
        }
        return R+1;
    }
};