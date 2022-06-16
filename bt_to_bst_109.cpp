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

void fill(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    res.push_back(root->data);
    fill(root->left, res);
    fill(root->right, res);
}
void bst(Node *&root, vector<int> res, int &i)
{
    if (root == NULL)
        return;
    bst(root->left, res, i);
    root->data = res[i++];
    bst(root->right, res, i);
}
Node *binaryTreeToBST(Node *root)
{
    vector<int> res;
    fill(root, res);
    sort(res.begin(), res.end());
    int i = 0;
    bst(root, res, i);
    return root;
}