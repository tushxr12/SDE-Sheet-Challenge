// Recursion
class Solution{   
private:
    bool f(int index, vector<int> &arr, int target)
    {
        if(target == 0)
            return true;

        if(index == 0)
        {
            if(target == arr[index])
                return true;
            return false;
        }
        
        bool notTake = f(index-1,arr,target);

        bool take = false;

        if(target >= arr[index])
        {
            take = f(index-1,arr,target-arr[index]);
        }

        return (take || notTake);
    }
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        return f(n-1,arr,target);
    }
};

// Memoization
class Solution{   
private:
    bool f(int index, vector<int> &arr, int target, vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;

        if(index == 0)
        {
            if(target == arr[index])
                return true;
            return false;
        }

        if(dp[index][target] != -1)
            return dp[index][target];

        bool notTake = f(index-1,arr,target,dp);

        bool take = false;

        if(target >= arr[index])
        {
            take = f(index-1,arr,target-arr[index],dp);
        }

        return dp[index][target] = (take || notTake);
    }
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        return f(n-1,arr,target,dp);
    }
};
