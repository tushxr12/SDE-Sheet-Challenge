class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> stt;

        for(int i = 0;i < n;i++)
        {
            set<int> st;
            for(int j = i + 1;j < n;j++)
            {
                int third = -(nums[i] + nums[j]);
                if(st.find(third) != st.end())
                {
                    vector<int> triplet = {nums[i], nums[j], third};
                    sort(begin(triplet), end(triplet));
                    stt.insert(triplet);
                }
                st.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(begin(stt), end(stt));
        return ans;
    }
};
