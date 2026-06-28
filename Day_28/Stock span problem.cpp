class Solution
{
    public:
    vector <int> stockSpan(vector<int> arr, int n) {
        vector<int> ans;

        for(int i = 0;i < n;i++)
        {
            int cnt = 1;
            int currElement = arr[i];

            for(int j = i - 1;j >= 0;j--)
            {
                if(arr[j] <= currElement){
                    cnt++;
                }
                else
                break;
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};
