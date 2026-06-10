class Solution{
public:
    int longestNonRepeatingSubstring(string& s){
        int maxLen = 0;
        int n = s.size();
        int l = 0, r = 0;
        vector<int> hash(256, -1);

        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);
            hash[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};
