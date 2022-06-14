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
vector<int> leftView(Node *root)
{
    vector<int> res;
    queue<Node *> q;
    if (root == NULL)
        return res;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; ++i)
        {
            Node *temp = q.front();
            q.pop();
            if (i == s-1)
                res.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return res;
}