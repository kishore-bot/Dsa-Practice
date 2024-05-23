// EASY
// PROBLEM OF DAY CODE STUDIO
// https://www.naukri.com/code360/problem-of-the-day/easy?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
vector<int> theOrder(int n)
{
    vector<int> ans;
    if (n <= 1)
        return {1};
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        q.push(k);
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}