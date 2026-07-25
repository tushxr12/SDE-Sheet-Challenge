// Recursion
class Solution{
  private:
    int f(int index,int n, vector<int> &price)
    {
        if(index == 0)
            return (n*price[0]);

        int notTake = f(index-1,n,price);

        int take = INT_MIN;
        int rodLength = index + 1;

        if(n >= rodLength)
        {
            take = price[index] + f(index,n-rodLength,price);
        }
        return max(take,notTake);
    }
  public:
    int rodCutting(vector<int> price, int n) {
        return f(n-1,n,price);
    }
};
