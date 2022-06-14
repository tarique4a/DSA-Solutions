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
vector<int> topView(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *f1 = it.first;
        // major diff between top view and bottom view
        int f2 = it.second; 
        m[f2] = f1->data;
        if (f1->left)
            q.push({f1->left, f2 - 1});
        if (f1->right)
            q.push({f1->right, f2 + 1});
    }
    for (auto it : m)
        res.push_back(it.second);

    return res;
}