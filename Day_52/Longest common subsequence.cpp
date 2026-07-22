class Solution {
  private:
    int func(string &s1, string &s2, int index1, int index2, vector<vector<int>> &dp)
    {
        if(index1 < 0 || index2 < 0)
            return 0;

        if(dp[index1][index2] != -1)
            return dp[index1][index2];
        
        if(s1[index1] == s2[index2])
            return dp[index1][index2] = 1 + func(s1,s2,index1-1,index2-1,dp);
        
        return dp[index1][index2] = max(func(s1,s2,index1-1,index2,dp), func(s1,s2,index1,index2-1,dp));
    }

  public:
    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n, vector<int>(m,-1));
        return func(str1, str2, n-1, m -1,dp);
    }
};
