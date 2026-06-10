class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = 0, xr = 0;
        map<int,int> mpp;
        mpp[xr]++;

        for(int i = 0;i < n;i++)
        {
            xr ^= nums[i];
            int x = xr ^ k;
            ans += mpp[x];
            mpp[xr]++;
        }
        return ans;
    }
};
