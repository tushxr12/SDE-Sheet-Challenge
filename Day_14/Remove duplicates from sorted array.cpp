class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st(begin(nums), end(nums));
        vector<int> temp(begin(st), end(st));
        nums = temp;
        return st.size();
    }
};

//Optimal
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = 1;

        for(int j = 1;j < n;j++)
        {
            if(nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return (i+1);
    }
};
