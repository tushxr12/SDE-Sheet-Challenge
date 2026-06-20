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
