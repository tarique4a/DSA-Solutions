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
Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
        return NULL;

    if (root->data == node)
        return root;

    Node *lft = solve(root->left, k, node);
    Node *rit = solve(root->right, k, node);

    if (lft != NULL && rit == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return lft;
    }
    if (lft == NULL && rit != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rit;
    }
    return nullptr;
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    return ans->data;
}