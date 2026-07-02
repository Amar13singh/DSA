#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    int arr;
    int idx;
};

struct cmp
{
    bool operator()(Node a, Node b)
    {
        return a.val > b.val;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& nums)
{
    priority_queue<Node, vector<Node>, cmp> pq;

    // Push first element of every non-empty array
    for (int i = 0; i < nums.size(); i++)
    {
        if (!nums[i].empty())
        {
            pq.push({nums[i][0], i, 0});
        }
    }

    vector<int> ans;

    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        ans.push_back(cur.val);

        int nextIdx = cur.idx + 1;

        if (nextIdx < nums[cur.arr].size())
        {
            pq.push({
                nums[cur.arr][nextIdx],
                cur.arr,
                nextIdx
            });
        }
    }

    return ans;
}