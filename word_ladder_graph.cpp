#include <bits/stdc++.h>
using namespace std;

int ladderLength(string start, string endw, vector<string> &wordList)
{
    queue<string> q;
    q.push(start);
    unordered_set<string> w(wordList.begin(), wordList.end());
    if (w.find(endw) == w.end())
        return 0;
    int len = 0;
    while (!q.empty())
    {
        len++;
        int sze = q.size();
        for (int j = 0; j < sze; ++j)
        {
            string s = q.front();
            q.pop();
            int ws = start.size();
            for (int i = 0; i < ws; i++)
            {
                char stor = s[i];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    s[i] = c;
                    if (s == endw)
                        return len + 1;
                    if (w.find(s) == w.end())
                        continue;

                    w.erase(s);
                    q.push(s);
                }
                s[i] = stor;
            }
        }
    }
    return 0;
}