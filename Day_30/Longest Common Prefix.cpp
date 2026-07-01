class Solution{	
	public:
		string longestCommonPrefix(vector<string>& str){
			//your code goes here
            if(str.empty())
                return "";
            
            sort(begin(str), end(str));
            int n = str.size();

            string first = str[0], last = str[n-1];

            int minLength = min(first.size(), last.size());
            string ans = "";

            for(int i = 0;i < minLength;i++)
            {
                if(first[i] != last[i]){
                    return ans;
                }
                ans += first[i];
            }
            return ans;
		}
};
