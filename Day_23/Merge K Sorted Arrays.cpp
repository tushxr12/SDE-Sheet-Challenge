class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {
        // Your code goes here
        vector<int> temp;

        for(int i = 0;i < arr.size();i++)
        {
            vector<int> currArray = arr[i];

            for(int j = 0;j < currArray.size();j++)
            {
                temp.push_back(currArray[j]);
            }
        }

        sort(begin(temp), end(temp));
        return temp;
    }
};
