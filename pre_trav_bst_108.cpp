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

int canRepresentBST(int arr[], int n)
{
    stack<int> s;
    int root = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < root)
            return false;
        while (!s.empty() && arr[i] > s.top())
        {
            root = s.top();
            s.pop();
        }
        s.push(arr[i]);
    }
    return true;
}