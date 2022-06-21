#include <bits/stdc++.h>
using namespace std;

bool ispar(string x)
{
    stack<char> s;
    for (int i : x)
    {
        if (s.empty() && (i == ']' || i == '}' || i == ')'))
            return false;
        if (i == '(' || i == '{' || i == '[')
            s.push(i);
        else if (s.top() == '(' && i == ')' ||
                 s.top() == '[' && i == ']' ||
                 s.top() == '{' && i == '}')
            s.pop();
        else
            return false;
    }
    if (s.empty())
        return true;
    return false;
}