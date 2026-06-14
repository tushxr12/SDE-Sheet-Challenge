class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int currOnes = 0;
        int n = nums.size();

        for(int i = 0;i < n;i++)
        {
            if(nums[i] == 1)
                currOnes++;
            else
                currOnes = 0;
            maxOnes = max(maxOnes, currOnes);
        }
        return maxOnes;
    }
};
