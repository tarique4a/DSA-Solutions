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
pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> res = {0, 0};
        return res;
    }
    pair<int, int> lft = solve(root->left);
    pair<int, int> rit = solve(root->right);
    pair<int, int> res;
    res.first = root->data + lft.second + rit.second;
    res.second = max(lft.first, lft.second) + max(rit.first, rit.second);
    return res;
}
int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}