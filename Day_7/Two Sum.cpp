class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n = nums.size();

        for(int i = 0;i < n;i++)
        {
            mpp[nums[i]] = i;
        }

        vector<int> ans;
        for(int i = 0;i < n;i++)
        {
            int currNum = nums[i];
            int need = target - currNum;

            if(mpp.find(need) != mpp.end() && mpp[need] != i)
            {
                ans.push_back(i);
                ans.push_back(mpp[need]);
                return ans;
            }
        }
        return ans;
    }
};
