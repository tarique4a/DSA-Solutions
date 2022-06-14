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

int mxsum = 0, mxlevel = 0;
void solve(Node *root, int sum, int level)
{
    if (!root)
        return;
    if (root->left)
        solve(root->left, sum + root->left->data, level + 1);
    if (root->right)
        solve(root->right, sum + root->right->data, level + 1);

    // if level is increased then simply replace the mxsum
    if (level > mxlevel)
    {
        mxlevel = level;
        mxsum = sum;
    }

    // else if in same level then we need to have the max sum
    else if (level == mxlevel)
    {
        mxsum = max(mxsum, sum);
    }
}
int sumOfLongRootToLeafPath(Node *root)
{
    if (!root)
        return 0;
    solve(root, root->data, 0);
    return mxsum;
}