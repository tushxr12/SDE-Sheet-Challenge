class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        // Your code goes here
        unordered_map<int,int> mpp;
        for(auto i : nums)
            mpp[i]++;
        
        vector<pair<int,int>> freqPairs(begin(mpp), end(mpp));
        sort(begin(freqPairs),end(freqPairs), [](auto &a, auto &b){
            return a.second > b.second;
        });

        vector<int> ans;
        for(int i = 0;i < k;i++)
        {
            int num = freqPairs[i].first;
            ans.push_back(num);
        }
        return ans;
    }
};

// Using heap
class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        // Your code goes here
        unordered_map<int,int> mpp;
        for(auto i : nums)
            mpp[i]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        for(auto &i : mpp)
        {
            minHeap.push({i.second, i.first});

            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> ans;
        while(!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};
