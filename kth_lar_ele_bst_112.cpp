#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void solve(Node *root, int k, int &c, int &ans)
{
    if (root == NULL)
        return;
    solve(root->right, k, c, ans);
    c++;
    if (c == k)
    {
        ans = root->data;
    }
    solve(root->left, k, c, ans);
}
int kthLargest(Node *root, int k)
{
    int c = 0;
    int ans;
    solve(root, k, c, ans);
    return ans;
}