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

Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL || root->data == n1 || root->data == n2)
        return root;
    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}

// To get distance from each nodes
int help(Node *root, int val)
{
    if (!root)
        return 0;
    if (root->data == val)
        return 1;
    int a = help(root->left, val);
    int b = help(root->right, val);
    if (!a and !b)
        return 0;
    else
        return a + b + 1;
}
int findDist(Node *root, int a, int b)
{
    Node *LCA = lca(root, a, b); // To Get LCA
    int ans1 = help(LCA, a);     // Distance from one val
    int ans2 = help(LCA, b);     // Distance from another val
    return ans1 + ans2 - 2;      // Because from help we are adding two extra values
}