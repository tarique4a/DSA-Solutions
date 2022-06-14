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

vector<int> diagonal(Node *root)
{
    vector<int> v;
    if (root == NULL)
        return v;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        while (temp)
        {
            if (temp->left)
                q.push(temp->left);
            v.push_back(temp->data);
            temp = temp->right;
        }
    }
    return v;
}