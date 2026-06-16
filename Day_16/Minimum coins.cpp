class Solution{
	public:
    int func(vector<int> &coins, int index, int target)
    {
        if(index == 0)
        {
            if(target % coins[0] == 0)
                return target / coins[0];
            else
                return 1e9;
        }

        int notTake = 0 + func(coins, index - 1, target);

        int take = 1e9;
        if(target >= coins[index])
        {
            take = 1 + func(coins, index, target - coins[index]);
        }

        return min(take, notTake);
    }

	int MinimumCoins(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = func(coins,n-1,amount);

        if(ans >= 1e9)
            return -1;
        
        return ans;
    }
};

// Memoized
class Solution{
	public:
    int func(vector<int> &coins, int index, int target,vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            if(target % coins[0] == 0)
                return target / coins[0];
            else
                return 1e9;
        }

        if(dp[index][target] != -1)
            return dp[index][target];

        int notTake = 0 + func(coins, index - 1, target, dp);

        int take = 1e9;
        if(target >= coins[index])
        {
            take = 1 + func(coins, index, target - coins[index], dp);
        }

        return dp[index][target] = min(take, notTake);
    }

	int MinimumCoins(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1,-1));
        int ans = func(coins,n-1,amount,dp);

        if(ans >= 1e9)
            return -1;
        
        return ans;
    }
};
