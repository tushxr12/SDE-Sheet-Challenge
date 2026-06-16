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
