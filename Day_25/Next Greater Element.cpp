// Brute
class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n,-1);

        for(int i = 0;i < n;i++)
        {
            int currElement = arr[i];

            for(int j = i + 1;j < n;j++)
            {
                if(arr[j] > currElement)
                {
                    ans[i] = arr[j];
                    break;
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;

        for(int i = n - 1;i >= 0;i--)
        {
            while(!st.empty() && st.top() <= arr[i])
                st.pop();
            
            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};
