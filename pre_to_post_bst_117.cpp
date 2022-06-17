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

Node *build(int pre[], int &i, int bound, int size)
{
    if (i >= size || pre[i] > bound)
        return NULL;
    Node *temp = new Node(pre[i++]);
    temp->left = build(pre, i, temp->data, size);
    temp->right = build(pre, i, bound, size);
    return temp;
}
Node *post_order(int pre[], int size)
{
    int i = 0;
    return build(pre, i, INT_MAX, size);
}