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
int check(Node *root, int &f)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->data;
    if (f == 0)
        return 0;
    int l = check(root->left, f);
    int r = check(root->right, f);
    if (l + r != root->data)
        f = 0;
    return l + r + root->data;
}
bool isSumTree(Node *root)
{
    int f = 1;
    check(root, f);
    return f;
}