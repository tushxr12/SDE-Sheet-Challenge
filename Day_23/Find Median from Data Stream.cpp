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

// Using heaps
class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return (maxHeap.top()*1.0 + minHeap.top()*1.0)/2.0;
        return maxHeap.top();
    }
};
