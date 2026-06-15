class Solution{  
  public:  
    bool static comp(vector<int> &v1, vector<int> &v2)
    {
        return v1[2] > v2[2];
    }

    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        //your code goes here
        sort(begin(Jobs), end(Jobs),comp);

        int n = Jobs.size();

        int maxDeadline = -1;
        for(auto it : Jobs)
        {
            maxDeadline = max(maxDeadline, it[1]);
        }

        vector<int> arr(maxDeadline + 1,-1);

        int cnt = 0, totalProfit = 0;

        for(int i = 0;i < n;i++)
        {
            for(int j = Jobs[i][1];j > 0;j--)
            {
                if(arr[j] == -1)
                {
                    cnt += 1;
                    totalProfit += Jobs[i][2];
                    arr[j] = Jobs[i][0];

                    break;
                }
            }
        }

        return {cnt, totalProfit};
    } 
};
