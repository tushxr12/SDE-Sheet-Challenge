class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        // Your code goes here
        vector<pair<double, int>> ratio;
        for(int i = 0;i < val.size();i++)
        {
            ratio.push_back({(double)val[i] / wt[i], i});
        }

        sort(rbegin(ratio), rend(ratio));
        double totalVal = 0.0;

        for(auto &i : ratio)
        {
            int index = i.second;
            if(wt[index] <= capacity)
            {
                totalVal += val[index];
                capacity -= wt[index];
            }
            else
            {
                totalVal += val[index] * ((double)capacity / wt[index]);
                break;
            }
        }
        return round(totalVal*1e6) / 1e6;
    }
};
