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
void solve(Node *root, int K, int &c, int &ans)
{
    if (root == NULL)
        return;
    solve(root->left, K, c, ans);
    c++;
    if (c == K)
    {
        ans = root->data;
    }
    solve(root->right, K, c, ans);
}
int KthSmallestElement(Node *root, int K)
{
    int c = 0;
    int ans = -1;
    solve(root, K, c, ans);
    return ans;
}