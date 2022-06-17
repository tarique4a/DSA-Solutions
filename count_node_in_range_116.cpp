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
void count(Node *root, int l, int h, int &c)
{
    if (root == NULL)
        return;
    count(root->left, l, h, c);
    if (root->data >= l && root->data <= h)
        c++;
    count(root->right, l, h, c);
}
int getCount(Node *root, int l, int h)
{
    int c = 0;
    count(root, l, h, c);
    return c;
}