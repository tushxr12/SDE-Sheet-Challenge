class Solution {
public:
    int kthLargestElement(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), greater<int>());
        return nums[k-1];
    }
};
