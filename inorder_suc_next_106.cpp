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

void solve(Node *root, Node *&prev)
{
    if (root == NULL)
        return;
    solve(root->left, prev);
    if (prev != NULL)
        prev->next = root;
    prev = root;
    solve(root->right, prev);
}

void populateNext(Node *root)
{
    Node *prev = NULL;
    solve(root, prev);
}