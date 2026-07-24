//Memo
class Solution {
private:
    int f(vector<int> &arr, int n,int prevIndex, int index, vector<vector<int>> &dp)
    {
        if(index == n)
            return 0;
        
        if(dp[index][prevIndex + 1] != -1)
            return dp[index][prevIndex + 1];

        int notTake = 0 + f(arr,n,prevIndex,index+1,dp);

        int take = 0;
        if(prevIndex == -1 || arr[index] > arr[prevIndex])
            take = arr[index] + f(arr,n,index,index+1,dp);
        
        return dp[index][prevIndex+1] = max(take,notTake);
    }
public:
    int maxSumIncreasingSubsequence(vector<int>& arr, int n) {
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return f(arr,n,-1,0,dp);
    }
};
