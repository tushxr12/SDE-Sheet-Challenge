// Recursion

class Solution {
  private:
    int mod = 1e9+7;
    int f(int index, vector<int> &coins, int target)
    {
        if(index == 0)
        {
            if(target%coins[index] == 0)
                return 1;
            return 0;
        }

        int notTake = f(index-1,coins,target);
        int take = 0;

        if(target >= coins[index])
        {
            take = f(index,coins,target-coins[index]); 
        }

        return (take+notTake)%mod;
    }
  public:
   int count(vector<int>&coins, int N, int amount) {
        return f(N-1,coins,amount);
    }
};

// Memoization
class Solution {
  private:
    int mod = 1e9+7;
    int f(int index, vector<int> &coins, int target, vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            if(target%coins[index] == 0)
                return 1;
            return 0;
        }

        if(dp[index][target] != -1)
            return dp[index][target];

        int notTake = f(index-1,coins,target,dp);
        int take = 0;

        if(target >= coins[index])
        {
            take = f(index,coins,target-coins[index],dp); 
        }

        return dp[index][target] = (take+notTake)%mod;
    }
  public:
   int count(vector<int>&coins, int N, int amount) {
        vector<vector<int>> dp(N, vector<int>(amount+1,-1));
        return f(N-1,coins,amount,dp);
    }
};
