class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto i : nums)
            mpp[i]++;
        for(auto i : mpp)
        {
            if(i.second > n/3){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
