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

// Optimal
class Solution {
public:
    void reverseString(string &s, int start, int end)
    {
        while(start < end){
            swap(s[start++], s[end--]);
        }
    }
    string reverseWords(string s) {
        int n = s.size();
        reverse(begin(s), end(s));
        vector<string> words;
        int start, end;
        int i = 0, j = 0;

        

        while(j < n)
        {
            while(j < n && s[j] == ' '){
                j += 1;
            }

            start = i;

            while(j < n && s[j] != ' '){
                s[i] = s[j];
                j++;
                i++;
            }

            end = i - 1;
            reverseString(s, start, end);

            if(j < n)
                s[i++] = ' ';
        }

        if(i > 0 && s[i-1] == ' ')
            i--;
        
        return s.substr(0, i);
    } 
};
