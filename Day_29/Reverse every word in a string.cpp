class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        vector<string> words;
        int start, end;

        while(i < n)
        {
            while(i < n && s[i] == ' ')
                i+=1;
            
            if(i >= n)
                break;
            
            start = i;

            while(i < n && s[i] != ' ')
                i += 1;
            
            end = i - 1;
            string currWord = s.substr(start, end - start + 1);
            words.push_back(currWord);
        }

        string ans = "";
        for(int i = words.size() - 1;i >= 0;i--){
            ans += words[i];
            if(i != 0)
                ans.push_back(' ');
        }
        return ans;
    } 
};
