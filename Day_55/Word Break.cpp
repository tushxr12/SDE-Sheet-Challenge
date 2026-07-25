// Recursion
class Solution {
private:
    bool solve(int index, int n, string &s)
    {
        if(index >= n)
            return true;
        
        if(st.find(s) != st.end())
            return true;
        
        for(int l = 1;l <= n;l++)
        {
            string temp = s.substr(index,l);

            if(st.find(temp) != st.end() && solve(index + l, n,s))
            {
                return true;
            } 
        }
        return false;
    }
public:
    unordered_set<string> st;
    bool wordBreak(string s, vector<string>& wordDict) {
        // Your code goes here
        int n = s.size();

        for(string &word : wordDict)
        {
            st.insert(word);
        }

        return solve(0,n,s);
    }
};

// Memoization
class Solution {
private:
    bool solve(int index, int n, string &s, vector<int> &dp)
    {
        if(index >= n)
            return true;
        
        if(st.find(s) != st.end())
            return true;
        
        if(dp[index] != -1)
            return dp[index];
        
        for(int l = 1;l <= n;l++)
        {
            string temp = s.substr(index,l);

            if(st.find(temp) != st.end() && solve(index + l, n,s,dp))
            {
                return dp[index] = true;
            } 
        }
        return dp[index]= false;
    }
public:
    unordered_set<string> st;
    bool wordBreak(string s, vector<string>& wordDict) {
        // Your code goes here
        int n = s.size();

        for(string &word : wordDict)
        {
            st.insert(word);
        }

        vector<int> dp(n,-1);
        return solve(0,n,s,dp);
    }
};
