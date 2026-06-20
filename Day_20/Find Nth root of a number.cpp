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
