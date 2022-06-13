#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> res;
    Node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    Node *start = head;
    while (start->data < tail->data)
    {
        if ((start->data + tail->data) == target)
        {
            res.push_back({start->data, tail->data});
            tail = tail->prev;
            start = start->next;
        }
        else if ((start->data + tail->data) > target)
        {
            tail = tail->prev;
        }
        else
        {
            start = start->next;
        }
    }
    return res;
}