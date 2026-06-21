class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        vector<int> temp;

        for(auto i : a)
            temp.push_back(i);
        for(auto i : b)
            temp.push_back(i);
        sort(begin(temp), end(temp));
        return temp[k-1];
    }
};
