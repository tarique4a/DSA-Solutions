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

void count(Node *root, int &c)
{
    if (root == NULL)
        return;
    c++;
    count(root->left, c);
    count(root->right, c);
}
void find(Node *root, int &key, int &k)
{
    if (root == NULL)
        return;
    find(root->left, key, k);
    k--;
    if (k == 0)
    {
        key = root->data;
        return;
    }
    find(root->right, key, k);
}
float findMedian(struct Node *root)
{
    // Code here
    //  count the number of nodes in bst;
    int c = 0;
    count(root, c);
    if (c % 2 != 0)
    {
        int k = (c + 1) / 2;
        int key;
        find(root, key, k);
        return key;
    }
    else
    {
        int k = c / 2;
        int p = k + 1;
        int key1, key2;
        find(root, key1, k);
        find(root, key2, p);
        return (key1 + key2) / 2.0;
    }
}