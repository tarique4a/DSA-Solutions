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

bool find(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (x > root->data)
        return find(root->right, x);
    else if (x < root->data)
        return find(root->left, x);
    else
        return true;
}
void solve(Node *root1, Node *root2, int x, int &c)
{
    if (root1 == NULL)
        return;
    solve(root1->left, root2, x, c);
    if (find(root2, x - root1->data))
    {
        c++;
    }
    solve(root1->right, root2, x, c);
}
int countPairs(Node *root1, Node *root2, int x)
{
    int c = 0;
    solve(root1, root2, x, c);
    return c;
}