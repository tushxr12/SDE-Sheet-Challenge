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

// Better
class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        int n = (n1 + n2);
        int i = 0, j = 0;
        int ind2 = (n/2);
        int ind1 = ind2 - 1;
        int cnt = 0;
        int ind1el = -1, ind2el = -1;

        while(i < n1 && j < n2)
        {
            if(arr1[i] < arr2[j])
            {
                if(cnt == ind1)
                    ind1el = arr1[i];
                if(cnt == ind2)
                    ind2el = arr1[i];
                i++;
                cnt++;
            }
            else
            {
                if(cnt == ind1)
                    ind1el = arr2[j];
                if(cnt == ind2)
                    ind2el = arr2[j];
                cnt++;
                j++;
            }
        }

        while(i < n1)
        {
            if(cnt == ind1)
            {
                ind1el = arr1[i];
            }
            if(cnt == ind2)
            {
                ind2el = arr1[i];
            }
            cnt++;
            i++;
        }

        while(j < n2)
        {
            if(cnt == ind1)
            {
                ind1el = arr2[j];
            }
            if(cnt == ind2)
            {
                ind2el = arr2[j];
            }
            cnt++;
            j++;
        }

        if(n%2)
            return ind2el;
        
        return (double)((double)(ind1el + ind2el)) / 2.0;
    }
};
