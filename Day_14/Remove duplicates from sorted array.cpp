class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st(begin(nums), end(nums));
        vector<int> temp(begin(st), end(st));
        nums = temp;
        return st.size();
    }
};
