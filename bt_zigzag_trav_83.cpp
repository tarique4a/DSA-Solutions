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
vector<int> zigZagTraversal(Node *root)
{
    // Code here
    vector<int> res;
    stack<Node *> s1, s2;
    if (root == NULL)
        return res;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        int n1 = s1.size();
        int n2 = s2.size();
        for (int i = 0; i < n1; ++i)
        {
            Node *t = s1.top();
            s1.pop();
            res.push_back(t->data);
            if (t->left)
                s2.push(t->left);
            if (t->right)
                s2.push(t->right);
        }
        for (int i = 0; i < n2; ++i)
        {
            Node *t = s2.top();
            s2.pop();
            res.push_back(t->data);
            if (t->right)
                s1.push(t->right);
            if (t->left)
                s1.push(t->left);
        }
    }
    return res;
}