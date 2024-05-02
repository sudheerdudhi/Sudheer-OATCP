#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> adj;
unordered_map<int, int> indeg, outdeg;

void build_graph(vector<vector<int>> &pairs)
{
    for (auto &edge : pairs)
    {
        int start = edge[0], end = edge[1];
        adj[start].push_back(end);
        outdeg[start]++;
        indeg[end]++;
    }
}

vector<int> v;

void dfs(int i)
{
    while (!adj[i].empty())
    {
        int j = adj[i].back();
        adj[i].pop_back();
        dfs(j);
    }
    v.push_back(i);
}
vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
{
    int e = pairs.size();
    build_graph(pairs);
    int i0 = outdeg.begin()->first;
    for (auto it = outdeg.begin(); it != outdeg.end(); ++it)
    {
        int v = it->first;
        int deg = it->second;
        if (deg == indeg[v] + 1)
        {
            i0 = v;
            break;
        }
    }

    dfs(i0);

    vector<vector<int>> ans;
    ans.reserve(e);

    for (int i = v.size() - 2; i >= 0; i--)
        ans.push_back({v[i + 1], v[i]});

    return ans;
}

int main()
{
     // below in freopen both line of code is changable acordangly input
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> pairs;
    for (int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;
        pairs.push_back({a, b});
    }

    vector<vector<int>> res = validArrangement(pairs);

    if (res.size() != pairs.size())
    {
        cout << "No valid arrangement possible" << endl;
        return 0;
    }

    for (auto pair : res)
    {
        cout << pair[0] << " " << pair[1] << endl;
    }
    cout << endl;
}