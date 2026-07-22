class Solution {
private:
    int f(int index, int prevIndex, vector<int> &nums, int n, vector<vector<int>> &dp)
    {
        if(index == n - 1)
        {
            if(prevIndex == -1 || nums[index] > nums[prevIndex])
                return 1;
            return 0;
        }

        if(dp[index][prevIndex+1] != -1)
            return dp[index][prevIndex+1];
        
        int notTake = 0 + f(index + 1, prevIndex, nums ,n, dp);

        int take = 0;

        if(prevIndex == -1 || nums[index] > nums[prevIndex])
        {
            take = 1 + f(index + 1, index, nums, n, dp);
        }
        return dp[index][prevIndex+1] = max(take, notTake);
    }
public:
    int LIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
    }    
};
