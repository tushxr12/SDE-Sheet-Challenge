class Solution{    
    public:
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
        //your code goes here
        sort(begin(Student), end(Student));
        sort(begin(Cookie), end(Cookie));

        int n = Student.size();
        int m = Cookie.size();

        int l = 0, r = 0;

        while(l < n && r < m)
        {
            if(Cookie[r] >= Student[l])
            {
                l+=1;
            }
            r += 1;
        }
        return l;
    }
};
