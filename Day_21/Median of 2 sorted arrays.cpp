class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
        vector<int> temp;
        for(auto i : arr1)
            temp.push_back(i);
        for(auto i : arr2)
            temp.push_back(i);
        sort(begin(temp), end(temp));

        int sz = arr1.size() + arr2.size();
        if(sz%2)
        {
            return (temp[sz/2] * 1.0);
        }
        double ans = (temp[sz/2] + temp[sz/2 - 1]) * 1.0;
        return (ans/2.0);
    }
};
