class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Your code goes here
        unordered_set<string> st(begin(wordDict), end(wordDict));
        int n = s.size();

        vector<bool> dp(n+1, false);
        dp[0] = true;

        int maxLen = 0;
        for(auto i : wordDict)
            maxLen = max(maxLen, (int)i.size());

        for(int i = 0;i < n;i++)
        {
            if(!dp[i])
                continue;
            
            for(int len = 1; len <= maxLen && i + len <= n;len++)
            {
                if(st.count(s.substr(i, len)))
                {
                    dp[i+len] = true;
                }
            }
        }
        return dp[n];
    }
};
