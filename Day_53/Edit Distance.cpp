class Solution {
  private:

    int f(int i,int j,string &s1, string &s2)
    {
        if(i < 0)
            return j + 1;
        if(j < 0)
            return i + 1;
        
        if(s1[i] == s2[j])
            return 0 + f(i-1,j-1,s1,s2);
        
        return 1 + min({f(i-1,j-1,s1,s2), f(i-1,j,s1,s2), f(i,j-1,s1,s2)});
        
    }
    
  public:
    int editDistance(string start, string target) {
        int n = start.size();
        int m = target.size();

        return f(n-1,m-1,start, target);
    }
};

