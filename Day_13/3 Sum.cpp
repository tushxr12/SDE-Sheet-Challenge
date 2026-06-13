class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> stt;

        for(int i = 0;i < n;i++)
        {
            set<int> st;
            for(int j = i + 1;j < n;j++)
            {
                int third = -(nums[i] + nums[j]);
                if(st.find(third) != st.end())
                {
                    vector<int> triplet = {nums[i], nums[j], third};
                    sort(begin(triplet), end(triplet));
                    stt.insert(triplet);
                }
                st.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(begin(stt), end(stt));
        return ans;
    }
};

// Optimal
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(begin(nums), end(nums));

        for(int i = 0;i <n;i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i + 1;
            int k = n - 1;

            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1])
                        j++;
                    while(j < k && nums[k] == nums[k+1])
                        k--;
                }
                else if(sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        return ans;
    }
};
