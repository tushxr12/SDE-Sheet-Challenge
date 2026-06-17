class Solution {
public:
    void func(int index, vector<int> &arr, vector<int> &candidates, int target, vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(arr);
            return;
        }

        if(target < 0 || index < 0)
            return;
        
        // Pick
        arr.push_back(candidates[index]);
        func(index,arr,candidates,target-candidates[index],ans);
        arr.pop_back();

        // Not Pick
        func(index-1,arr,candidates,target,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //your code goes here
        vector<vector<int>> ans;
        vector<int> arr;
        int n = candidates.size();
        func(n-1,arr,candidates,target,ans);
        return ans;
    }
};
