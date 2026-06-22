class Solution {
public:
  vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k) {
        sort(begin(nums1), end(nums1), greater<int>());
        sort(begin(nums2), end(nums2), greater<int>());

        priority_queue<pair<int, pair<int,int>>> pq;
        set<pair<int,int>> visited;

        pq.push({nums1[0] + nums2[0], {0,0}});
        visited.insert({0,0});

        vector<int> ans;

        while(k-- && !pq.empty())
        {
            auto [sum, index] = pq.top();
            pq.pop();
            
            int i = index.first, j = index.second;

            ans.push_back(sum);

            if(i + 1 < nums1.size() && !visited.count({i+1,j}))
            {
                pq.push({nums1[i+1] + nums2[j], {i + 1,j}});
                visited.insert({i+1,j});
            }

            if(j + 1 < nums2.size() && !visited.count({i,j+1}))
            {
                pq.push({nums1[i] + nums2[j+1], {i, j + 1}});
                visited.insert({i,j + 1});
            }
        }
        return ans;
  }
};
