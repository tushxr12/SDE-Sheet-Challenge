class Solution {
public:
 vector<int> distinctNumbers(vector<int>& nums, int k) {
    // Your code goes here
    int n = nums.size();
    vector<int> ans;
    unordered_map<int,int> freq;

    for(int i = 0;i < k;i++)
    freq[nums[i]]++;

    ans.push_back((int)freq.size());

    for(int i = k;i < n;i++)
    {
        int outgoing = nums[i-k];
        freq[outgoing]--;

        if(freq[outgoing] == 0)
            freq.erase(outgoing);
        
        int incoming = nums[i];
        freq[incoming]++;

        ans.push_back((int)freq.size());
    }
    return ans;
 }
};
