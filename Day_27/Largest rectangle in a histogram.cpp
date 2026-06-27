class Solution
{
private:
    vector<int> findNSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1;i >= 0;i--)
        {
            int currElement = arr[i];

            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0;i < n;i++)
        {
            int currElement = arr[i];

            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(st.empty())
                ans[i] = -1;
            else    
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int> &heights) {
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);

        int maxArea = 0;
        int n = heights.size();

        for(int i = 0;i < n;i++)
        {
            int currArea = (nse[i] - pse[i] - 1) * heights[i];
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }
};
