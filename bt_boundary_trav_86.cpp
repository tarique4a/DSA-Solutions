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
void leftnode(Node *root, vector<int> &v)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    if (root->left == NULL && root->right != NULL)
    {
        v.push_back(root->data);
        leftnode(root->right, v);
    }
    else
    {
        v.push_back(root->data);
        leftnode(root->left, v);
    }
}
void leaf(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        v.push_back(root->data);
    leaf(root->left, v);
    leaf(root->right, v);
}
void rit(Node *root, vector<int> &v)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->right == NULL && root->left != NULL)
    {
        rit(root->left, v);
        v.push_back(root->data);
    }
    else
    {
        rit(root->right, v);
        v.push_back(root->data);
    }
}
vector<int> boundary(Node *root)
{
    vector<int> v;
    if (root == NULL)
        return v;
    v.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
        return v;
    leftnode(root->left, v);
    leaf(root, v);
    rit(root->right, v);
    return v;
}