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

vector<Node *> v;
unordered_map<string, int> m;
string solve(Node *root)
{

    if (!root)
        return "";

    string left = solve(root->left);
    string right = solve(root->right);

    string ans = to_string(root->data) + "$" + left + "$" + right;

    if (m[ans] == 1)
        v.push_back(root);

    m[ans]++;

    return ans;
}
vector<Node *> printAllDups(Node *root)
{
    // Code here
    m.clear();
    v.clear();
    solve(root);

    return v;
}