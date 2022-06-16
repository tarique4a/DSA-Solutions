#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};
void successor(Node *root, Node *&suc, int key)
{

    while (root != NULL)
    {
        if (root->key <= key)
        {
            root = root->right;
        }
        else
        {
            suc = root;
            root = root->left;
        }
    }
}
void predecessor(Node *root, Node *&pre, int key)
{
    while (root != NULL)
    {
        if (root->key >= key)
        {
            root = root->left;
        }
        else
        {
            pre = root;
            root = root->right;
        }
    }
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    successor(root, suc, key);
    predecessor(root, pre, key);
}