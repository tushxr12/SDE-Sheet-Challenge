class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
        vector<int> temp;
        for(int i = 0;i < matrix.size();i++)
        {
            for(int j = 0;j < matrix[0].size();j++)
            {
                temp.push_back(matrix[i][j]);
            }
        }

        sort(begin(temp), end(temp));
        int n = matrix.size();
        int m = matrix[0].size();
        return temp[(n*m)/2];
    }
};

// Optimal
class Solution{
public:
    int func(vector<vector<int>> &matrix, int mid)
    {
        int cnt = 0;
        for(int i = 0;i < matrix.size();i++)
        {
            cnt += (upper_bound(begin(matrix[i]), end(matrix[i]),mid) - begin(matrix[i]));
        }
        return cnt;
    }

    int findMedian(vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        for(int i = 0;i < n;i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m-1]);
        }

        while(low <= high)
        {
            int mid = (low + high)/2;
            int smallerEquals = func(matrix, mid);
            int req = (n*m)/2;
            if(smallerEquals <= req)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
