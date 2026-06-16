class Solution {
public:
    void func(int index, vector<int> &arr, vector<int> &nums, vector<vector<int>> &ans)
    {
        if(index == nums.size())
        {
            ans.push_back(arr);
            return;
        }

        arr.push_back(nums[index]);
        func(index + 1, arr, nums, ans);
        arr.pop_back();

        for(int j = index + 1;j < nums.size();j++)
        {
            if(nums[j] != nums[index])
            {
                func(j,arr,nums,ans);
                return;
            }
        }

        func(nums.size(),arr,nums,ans);
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        //your code goes here
        vector<vector<int>> ans;
        vector<int> arr;
        sort(begin(nums), end(nums));
        func(0,arr,nums,ans);
        return ans;
    }
};
