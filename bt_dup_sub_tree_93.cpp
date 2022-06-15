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
unordered_map<string, int> m;

string formSubtree(Node *root)
{
    if (root == NULL)
    {
        return "$";
    }
    string s = "";
    if (root->right == NULL && root->left == NULL)
    {
        s = to_string(root->data);
        return s;
    }
    s = s + to_string(root->data);
    s = s + formSubtree(root->left);
    s = s + formSubtree(root->right);
    m[s]++;
    return s;
}
int dupSub(Node *root)
{
    m.clear();
    formSubtree(root);
    for (auto x : m)
    {
        if (x.second >= 2)
        {
            return true;
        }
    }
    return false;
}