class MedianFinder {
    vector<int> nums;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        if(nums.empty())
        {
            return 0.0;
        }

        vector<int> sortedNums = nums;
        sort(begin(sortedNums), end(sortedNums));
        int n = sortedNums.size();

        if(n%2)
            return (double) sortedNums[n/2];
        else
        {
            double a = (double) sortedNums[n/2];
            double b = (double) sortedNums[(n/2) - 1];

            return (a + b)/(2.0);
        }
    }
};
