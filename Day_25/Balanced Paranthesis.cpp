class Solution {
public:
    bool isOpeningBracket(char &ch)
    {
        return ((ch == '(') || (ch == '{') || (ch == '['));
    }

    bool isValid(string str) {
       stack<char> st;

       for(auto &ch : str)
       {
            if(isOpeningBracket(ch))
            {
                st.push(ch);
            }
            else
            {
                if(st.empty())
                    return false;
                    
                if((st.top() == '(' && ch == ')') || (st.top() == '[' && ch == ']') || (st.top() == '{' && ch == '}'))
                {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
       }

       if(st.empty())
        return true;
       return false;
    }
};
