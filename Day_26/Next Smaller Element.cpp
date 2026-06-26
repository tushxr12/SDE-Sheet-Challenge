class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        vector<int> ans(n, -1);

        for(int i = 0;i < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                if(arr[i] > arr[j])
                {
                    ans[i] = arr[j];
                    break;
                }
            }
        }
        return ans;
    }
};
