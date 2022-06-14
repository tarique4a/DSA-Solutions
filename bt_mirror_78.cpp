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
void mirror(Node *root)
{
    // code here
    if (root == NULL)
        return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
    return;
}