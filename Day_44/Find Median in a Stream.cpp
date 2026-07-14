class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // Your code goes here
        vector<int> sortedList;
        vector<double> medians;

        for(auto num : arr)
        {
            sortedList.insert(lower_bound(begin(sortedList), end(sortedList), num), num);

            int n = sortedList.size();

            if(n%2)
            {
                medians.push_back(sortedList[n/2]);
            }
            else
            {
                medians.push_back((sortedList[n/2 - 1] + sortedList[n/2]) / 2.0);
            }
        }
        return medians;
    }
};
