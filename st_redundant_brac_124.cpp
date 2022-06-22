#include <bits/stdc++.h>
using namespace std;

int checkRedundancy(string s)
{
    stack<char> st;

    for (char ch : s)
    {
        if (ch == ')')
        {
            // go town till encounter '('
            bool flag = false;
            while (!st.empty() and st.top() != '(')
            {
                if (st.top() == '+' or st.top() == '*' or st.top() == '/' or st.top() == '-')
                {
                    flag = true;
                }
                st.pop();
            }
            if (flag == false)
            {
                return 1;
            }
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }
    return 0;
}