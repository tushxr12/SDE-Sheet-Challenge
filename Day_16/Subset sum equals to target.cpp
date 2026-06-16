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
