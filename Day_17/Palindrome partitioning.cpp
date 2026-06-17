class Solution {
public:
    bool isPalinndrome(string s, int left, int right)
    {
        while(left <= right)
        {
            if(s[left++] != s[right--])
                return false;
        }
        return true;
    }

    void func(int index, string s, vector<string> &path, vector<vector<string>>& ans)
    {
        if(index == s.size())
        {
            ans.push_back(path);
            return;
        }

        for(int i = index;i < s.size();i++)
        {
            if(isPalinndrome(s, index, i))
            {
                path.push_back(s.substr(index,i - index + 1));
                func(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string> > partition(string s) {
        //your code goes here
        vector<vector<string>> ans;
        vector<string> arr;
        func(0, s, arr, ans);
        return ans;
    }
};
