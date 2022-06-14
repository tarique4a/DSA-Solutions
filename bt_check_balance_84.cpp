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
int help(Node *root)
{
    if (root == NULL)
        return 0;
    int lhs = help(root->left);
    if (lhs == -1)
        return -1;
    int rhs = help(root->right);
    if (rhs == -1)
        return -1;
    if (abs(lhs - rhs) > 1)
        return -1;
    return 1 + max(lhs, rhs);
}
bool isBalanced(Node *root)
{
    return help(root) != -1;
}