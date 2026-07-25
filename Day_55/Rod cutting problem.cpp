// Recursion
class Solution{
  private:
    int f(int index,int n, vector<int> &price)
    {
        if(index == 0)
            return (n*price[0]);

        int notTake = f(index-1,n,price);

        int take = INT_MIN;
        int rodLength = index + 1;

        if(n >= rodLength)
        {
            take = price[index] + f(index,n-rodLength,price);
        }
        return max(take,notTake);
    }
  public:
    int rodCutting(vector<int> price, int n) {
        return f(n-1,n,price);
    }
};

// Memoization
class Solution{
  private:
    int f(int index,int n, vector<int> &price, vector<vector<int>> &dp)
    {
        if(index == 0)
            return (n*price[0]);

        if(dp[index][n] != -1)
            return dp[index][n];

        int notTake = f(index-1,n,price,dp);

        int take = INT_MIN;
        int rodLength = index + 1;

        if(n >= rodLength)
        {
            take = price[index] + f(index,n-rodLength,price,dp);
        }
        return dp[index][n] = max(take,notTake);
    }
  public:
    int rodCutting(vector<int> price, int n) {
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};
