class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < i;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0;i < n;i++)
        {
            reverse(begin(matrix[i]), end(matrix[i]));
        }
    }
};
