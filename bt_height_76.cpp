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
int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    int l = height(node->left);
    int r = height(node->right);
    return max(l, r) + 1;
}