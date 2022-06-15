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
unordered_map<int, int> mp;
int ind;

Node *helper(int pre[], int in[], int i, int j)
{
    if (i > j)
        return (nullptr);
    int d = pre[ind++];
    Node *node = new Node(d);
    if (i == j)
        return (node);
    int mid = mp[d];
    node->left = helper(pre, in, i, mid - 1);
    node->right = helper(pre, in, mid + 1, j);
    return (node);
}

Node *buildTree(int in[], int pre[], int n)
{
    mp.clear();
    ind = 0;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    return helper(pre, in, 0, n - 1);
}