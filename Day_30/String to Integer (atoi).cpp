class Solution {
public:
    int myAtoi(string input) {
        // Your code goes here
        int i = 0, n = input.size();

        while(i < n && input[i] == ' ')
            i += 1;
        
        int sign = 1;
        if(i < n && input[i] == '-'){
            sign = -1;
            i++;
        }
        else if(i < n && input[i] == '+')
        {
            i++;
        }

        long long ans = 0;
        while(i < n && isdigit(input[i])){
            ans = ans * 10 + (input[i] - '0');
            i++;

            if(ans * sign >= INT_MAX)
                return INT_MAX;
            
            if(ans * sign <= INT_MIN)
                return INT_MIN;
        }

        return (ans * sign);
    }
};
