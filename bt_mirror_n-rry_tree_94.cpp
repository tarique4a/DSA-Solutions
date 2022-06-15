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

int checkMirrorTree(int n, int e, int A[], int B[])
{
    unordered_map<int, vector<int>> m1;
    unordered_map<int, vector<int>> m2;
    for (int i = 0; i < 2 * e; i += 2)
    {
        m1[A[i]].push_back(A[i + 1]);
    }
    for (int i = 0; i < 2 * e; i += 2)
    {
        m2[B[i]].push_back(B[i + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        reverse(m1[i].begin(), m1[i].end());
        if (m1[i] != m2[i])
            return 0;
    }

    return 1;
}