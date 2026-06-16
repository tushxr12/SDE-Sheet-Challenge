class Solution{   
public:
    bool func(int index, vector<int> &arr, int target)
    {
        if(target == 0)
            return true;

        if(index == 0)
        {
            return (target == arr[index]);
        }

        bool notTake = func(index - 1, arr, target);

        bool take = false;
        if(target >= arr[index])
            take = func(index-1,arr,target - arr[index]);

        return (take || notTake);
    }

    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        return func(n-1, arr, target);
    }
};

// Memoized
class Solution{   
public:
    bool func(int index, vector<int> &arr, int target, vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;

        if(index == 0)
        {
            return (target == arr[index]);
        }

        if(dp[index][target] != -1)
            return dp[index][target];

        bool notTake = func(index - 1, arr, target, dp);

        bool take = false;
        if(target >= arr[index])
            take = func(index-1,arr,target - arr[index], dp);

        return dp[index][target] = (take || notTake);
    }

    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1,-1));
        return func(n-1, arr, target, dp);
    }
};
