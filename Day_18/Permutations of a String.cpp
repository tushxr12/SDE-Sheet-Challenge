class Solution {
public:
    void func(vector<bool> &used, string &path, string &s, vector<string> &ans)
    {
        if(path.size() == s.size())
        {
            ans.push_back(path);
            return;
        }

        for(int i = 0;i < s.size();i++){
            if(used[i])
                continue;
            
            if(i > 0 && s[i] == s[i-1] && !used[i-1])
                continue;
            
            used[i] = true;
            path.push_back(s[i]);
            func(used,path,s,ans);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<string> permuteUnique(string s) {
        // Your code goes here
        sort(begin(s), end(s));

        vector<string> ans;
        string path;
        vector<bool> used(s.size(), false);
        func(used, path, s, ans);
        return ans;
    }
};
