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
void fun(Node *root, int &ans)
{
int prev = INT_MIN;
    if (!root)
        return;
    fun(root->left, ans);
    if (prev > root->data)
        ans = 0;
    else
        prev = root->data;
    fun(root->right, ans);
    return;
}
bool isBST(Node *root)
{
    int ans = 1;
    fun(root, ans);
    return ans;
}