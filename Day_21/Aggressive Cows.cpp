class Solution {
public:
    bool canWePlace(vector<int> &nums, int distance, int cows)
    {
        int cntCows = 1, last = nums[0];

        for(int i = 1;i < nums.size();i++)
        {
            if(nums[i] - last >= distance)
            {
                cntCows++;
                last = nums[i];
            }
            if(cntCows >= cows)
            {
                return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int maxi = *max_element(begin(nums), end(nums));
        int mini = *min_element(begin(nums), end(nums));

        for(int i = 1;i <= maxi - mini;i++)
        {
            if(!canWePlace(nums,i,k))
            {
                return (i-1);
            }
        }
        return (maxi - mini);
    }
};
