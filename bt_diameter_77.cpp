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
int height(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lft = height(root->left, maxi);
    int rit = height(root->right, maxi);
    maxi = max(maxi, lft + rit);
    return 1 + max(lft, rit);
}
int diameter(Node *root)
{
    int dai = 0;
    height(root, dai);
    return dai + 1;
}