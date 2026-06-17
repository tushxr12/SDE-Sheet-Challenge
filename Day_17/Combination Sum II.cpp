class Solution {
public:
    void func(int index, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &nums)
    {
        if(target == 0)
        {
            ans.push_back(nums);
            return;
        }

        if(target < 0 || index < 0)
            return;
        
        // Pick
        nums.push_back(candidates[index]);
        func(index-1, target - candidates[index], candidates, ans, nums);
        nums.pop_back();

        // Not pcik (any duplicates as well)
        for(int i = index - 1;i >= 0;i--)
        {
            if(candidates[index] != candidates[i])
            {
                func(i, target, candidates, ans, nums);
                break;
            }
        }
        func(-1, target, candidates, ans, nums);
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        //your code goes here
        vector<vector<int>> ans;
        vector<int> arr;
        sort(begin(candidates), end(candidates));
        func(candidates.size() - 1, target, candidates, ans, arr);
        return ans;
    }
};
