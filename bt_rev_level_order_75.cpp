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
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> v;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            Node *t = q.front();
            v.push_back(t->data);
            q.pop();
            if (t->right)
                q.push(t->right);
            if (t->left)
                q.push(t->left);
        }
    }
    reverse(v.begin(), v.end());
    return v;
}