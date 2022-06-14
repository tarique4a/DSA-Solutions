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
int getSum(Node *node)
{
    if (!node)
    {
        return 0;
    }
    int x = 0;
    if (!node->left && node->right)
    {
        x = node->right->data;
    }
    else if (node->left && !node->right)
    {
        x = node->left->data;
    }
    else if (node->left && node->right)
    {
        x = node->left->data + node->right->data;
    }
    int l = getSum(node->left);
    int r = getSum(node->right);

    return l + r + x;
}
void toSumTree(Node *node)
{
    // Your code here
    if (!node)
    {
        return;
    }
    node->data = getSum(node);
    toSumTree(node->left);
    toSumTree(node->right);
}