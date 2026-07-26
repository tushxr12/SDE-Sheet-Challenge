class Solution {
public:
    int n;
    int dp[50001];
    int getNextIndex(vector<vector<int>> &arr, int l, int currJobEnd)
    {
        int r = n - 1;
        int res = n + 1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;

            if(arr[mid][0] >= currJobEnd)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }

    int solve(int index, vector<vector<int>> &arr)
    {
        if(index >= n)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int notTake = 0 + solve(index + 1, arr);

        int nextJobIndex = getNextIndex(arr, index + 1, arr[index][1]);
        int take = arr[index][2] + solve(nextJobIndex, arr);

        return dp[index] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // Your code goes here
        n = startTime.size();
        memset(dp, -1, sizeof(dp));

        vector<vector<int>> arr(n, vector<int>(3,0));

        for(int i = 0;i < n;i++)
        {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        auto comp = [&](auto &vec1, auto&vec2)
        {
            return vec1[0] <= vec2[0];
        };

        sort(begin(arr), end(arr), comp);
        return solve(0,arr);
    }
};
