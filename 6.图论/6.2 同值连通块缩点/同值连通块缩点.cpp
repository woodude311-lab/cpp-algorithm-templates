#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
struct ShrinkResult
{
    int bcnt;                  // 块的数量
    vector <int> bid;           // 原节点所属块的编号
    vector <int> bvalue;        // 每个块的值
    vector <int> bsize;         // 每个块包含的原节点数量
    vector <vector <int>> graph; // 缩点后的图
};
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> value(n);
    for(int i = 0;i < n;i++)
    {
        cin >> value[i];
    }
    vector <vector <int>> adj(n);
    vector <pair <int, int>> edges;
    for(int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }
    // ----------同值连通块缩点----------
    auto shrink = [&]() -> ShrinkResult
    {
        vector <int> bid(n,-1);
        vector <int> bvalue;
        vector <int> bsize;
        int bcnt = 0;
        // 1. BFS 找出所有同值连通块
        for(int start = 0;start < n;start++)
        {
            if(bid[start] != -1) continue;
            queue <int> q;
            int sz = 0;
            bid[start] = bcnt;
            q.push(start);
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                sz++;
                for(int v : adj[u])
                {
                    if(bid[v] == -1 && value[v] == value[u])
                    {
                        bid[v] = bcnt;
                        q.push(v);
                    }
                }
            }
            bvalue.push_back(value[start]);
            bsize.push_back(sz);
            bcnt++;
        }
        // 2. 将原边映射为块之间的边
        vector<pair<int, int>> bedges;
        for(const auto& [u, v] : edges)
        {
            int a = bid[u];
            int b = bid[v];
            if(a == b) continue;
            if(a > b) swap(a, b);
            bedges.push_back({a, b});
        }
        // 3. 去掉重复边
        sort(bedges.begin(), bedges.end());
        bedges.erase(unique(bedges.begin(), bedges.end()),bedges.end());
        // 4. 建立缩点后的邻接表
        vector <vector <int>> graph(bcnt);
        for(const auto& [a, b] : bedges)
        {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        return {bcnt, bid, bvalue, bsize, graph};
    };
    // ----------调用模板----------
    auto [bcnt, bid, bvalue, bsize, graph] = shrink();
    return 0;
}
