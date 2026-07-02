class Solution{	
	public:
		bool anagramStrings(string& s,string t){
			//your code goes here
            sort(begin(s), end(s));
            sort(begin(t), end(t));
            return (s == t);
		}
};
