class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int index = -1;

        for(int i = n - 1;i > 0;i--){
            if(nums[i] > nums[i-1]){
                index = i-1;
                break;
            }
        }   

        if(index != -1)
        {
            for(int j = n - 1;j >= index + 1;j--){
                if(nums[j] > nums[index]){
                    swap(nums[index], nums[j]);
                    break;
                }
            }
            
        }

        return reverse(begin(nums) + index + 1, end(nums));
        
    }
};
