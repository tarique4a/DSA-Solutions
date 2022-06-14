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

set<int> s;
bool check(Node *root, int l = 0)
{

    if (root == NULL)
        return true;
    if (!root->left && !root->right)
        s.insert(l);

    check(root->left, l + 1);
    check(root->right, l + 1);

    return s.size() == 1;
}