#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
vector<int> levelOrder(Node *node)
{
    vector<int> res;
    queue<Node *> q;
    if (node == NULL)
        return res;
    q.push(node);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; ++i)
        {
            res.push_back(q.front()->data);
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
    }
    return res;
}