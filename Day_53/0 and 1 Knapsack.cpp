// Recursion
class Solution{
    private:
        int func(int index, int weight, vector<int> &wt, vector<int> &val)
        {
            if(index == 0)
            {
                if(weight >= wt[0])
                    return val[0];
                return 0;
            }

            int notPick = 0 + func(index - 1,weight,wt,val);

            int pick = INT_MIN;

            if(weight >= wt[index])
            {
                pick = val[index] + func(index-1,weight-wt[index],wt,val);
            }

            return max(pick, notPick);
        }
    public:
        int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
            //your code goes here
            return func(n-1,W,wt,val);
        }
};

// Memoization
class Solution{
    private:
        int func(int index, int weight, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
        {
            if(index == 0)
            {
                if(weight >= wt[0])
                    return val[0];
                return 0;
            }

            if(dp[index][weight] != -1)
                return dp[index][weight];

            int notPick = 0 + func(index - 1,weight,wt,val,dp);

            int pick = INT_MIN;

            if(weight >= wt[index])
            {
                pick = val[index] + func(index-1,weight-wt[index],wt,val,dp);
            }

            return dp[index][weight] = max(pick, notPick);
        }
    public:
        int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
            //your code goes here
            vector<vector<int>> dp(n, vector<int>(W+1,-1));
            return func(n-1,W,wt,val,dp);
        }
};
