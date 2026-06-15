class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //your code goes here
        int n = Arrival.size();

        sort(begin(Arrival), end(Arrival));
        sort(begin(Departure), end(Departure));

        int ans = 1, cnt = 1, i = 1, j = 0;

        while(i < n && j < n)
        {
            if(Arrival[i] <= Departure[j])
            {
                cnt+=1;
                i += 1;
            }
            else
            {
                cnt -= 1;
                j += 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
