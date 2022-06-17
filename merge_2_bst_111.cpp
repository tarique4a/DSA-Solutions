#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void fill(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;
    fill(root->left, in);
    in.push_back(root->data);
    fill(root->right, in);
}
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> res;
    fill(root1, res);
    fill(root2, res);
    sort(res.begin(), res.end());
    return res;
}