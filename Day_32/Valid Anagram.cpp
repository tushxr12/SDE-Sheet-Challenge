class Solution{	
	public:
		bool anagramStrings(string& s,string t){
			//your code goes here
            sort(begin(s), end(s));
            sort(begin(t), end(t));
            return (s == t);
		}
};

// Better
class Solution{	
	public:
		bool anagramStrings(string& s,string t){
			//your code goes here
            if(s.size() != t.size())
                return false;
            
            vector<int> freq(26, 0);

            for(char c : s)
            {
                freq[c-'a']++;
            }

            for(char c : t)
            {
                freq[c-'a']--;
            }

            for(auto i : freq){
                if(i != 0)
                    return false;
            }
            return true;
		}
};
