
// Brutte
vector<int> inersection(int a1[], int a2[], int n, int m)
{
    vector<int> ans;
    vector<int> vis(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; j++)
        {
            if (a1[i] == a2[j] and vis[j] == 0)
            {
                vis[j] = 1;
                ans.push_back(a2[j]);
                break;
            }
            if (a2[j] > a1[i])
                break;
        }
        return ans;
    }
}

// Optimal

vector<int> inersection(int a1[], int a2[], int n, int m)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n and j < m)
    {
        if (a1[i] < a2[j])
            i++;
        else if (a1[i] > a2[j])
            j++;
        else{
            ans.push_back(a2[j]);
            i++;
            j++;
        }
    }
    return ans;
}