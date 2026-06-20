class Solution {
public:
  int NthRoot(int N, int M) {
    for(int i = 1;i <= M;i++)
    {
        long long val = pow(i, N);

        if(val == M*1ll)
            return i;
        else if(val > M*1ll)
            break;
    }
    return -1;
  }
};


// Optimal
class Solution {
public:
  long long check(long long mid, int n, int m)
  {
    long long ans = 1;
    for(int i = 1;i <= n;i++){
        ans *= mid;
        if(ans > m)
            return 2;
    }
    if(ans == m)
        return 1;
    return 0;
  }

  int NthRoot(int N, int M) {
    long long low = 1, high = M;

    while(low <= high)
    {
        long long mid = (low + high)/2;
        long long curr = check(mid,N,M);

        if(curr == 1)
        {
            return mid;
        }
        else if(curr == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
  }
};
