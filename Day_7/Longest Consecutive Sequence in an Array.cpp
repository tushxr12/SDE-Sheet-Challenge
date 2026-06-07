// Better
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        sort(begin(nums), end(nums));

        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longestConsecutive = 0;

        for(int i = 0;i < n;i++)
        {
            if(nums[i] - 1 == lastSmaller)
            {
                cnt += 1;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller)
            {
                lastSmaller = nums[i];
                cnt = 1;
            }
            longestConsecutive = max(longestConsecutive, cnt);
        }
        return longestConsecutive;
    }
};
