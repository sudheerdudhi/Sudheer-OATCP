#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

bool bfs(vector<vector<int>> &g, int s, int t, vector<int> &p)
{
    int V = g.size();
    vector<bool> vis(V, false);

    queue<int> q;
    q.push(s);
    vis[s] = true;
    p[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (!vis[v] && g[u][v] > 0)
            {
                q.push(v);
                p[v] = u;
                vis[v] = true;
            }
        }
    }
    return vis[t];
}

int fordFulkerson(vector<vector<int>> &g, int s, int t)
{
    int V = g.size();
    vector<vector<int>> rG(V, vector<int>(V, 0));
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            rG[u][v] = g[u][v];
        }
    }

    vector<int> p(V);
    int max_flow = 0;

    while (bfs(rG, s, t, p))
    {
        int flow = INT_MAX;
        for (int v = t; v != s; v = p[v])
        {
            int u = p[v];
            flow = min(flow, rG[u][v]);
        }

        for (int v = t; v != s; v = p[v])
        {
            int u = p[v];
            rG[u][v] -= flow;
            rG[v][u] += flow;
        }

        max_flow += flow;
    }

    return max_flow;
}

signed main()
{
    // below in freopen both line of code is changable acordangly input
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int src, dest;
    cin >> src >> dest;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    int node1, node2, weight;
    while (cin >> node1 >> node2 >> weight)
    {
        graph[node1][node2] = weight;
    }
    cout << "Output is : " << fordFulkerson(graph, src, dest) << endl;

    return 0;
}