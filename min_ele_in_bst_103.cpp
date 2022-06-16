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

int solve(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    if (root->left == NULL)
    {
        return root->data;
    }
    solve(root->left);
}
int minValue(Node *root)
{
    if (root == NULL)
        return -1;
    int ans = solve(root);
    return ans;
}