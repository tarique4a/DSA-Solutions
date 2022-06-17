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
Node *solve(vector<int> in, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;
    Node *root = new Node(in[mid]);
    root->left = solve(in, s, mid - 1);
    root->right = solve(in, mid + 1, e);
    return root;
}
Node *buildBalancedTree(Node *root)
{
    vector<int> in;
    fill(root, in);
    int s = 0, e = in.size() - 1;
    return solve(in, s, e);
}