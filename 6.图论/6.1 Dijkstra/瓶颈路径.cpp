#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <algorithm>
using namespace std;
struct edge
{
        int to;
        long long weight;
};
int main()
{
    const long long INF = numeric_limits <long long>::max() / 4;
    const long long NEG_INF = numeric_limits <long long>::min() / 4;
    int n,m,s;
    cin >> n >> m >> s;
    vector <vector <edge>> adj(n);
    for(int i = 0;i < m;i++)
    {
        int u,v;
        long long weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});     // 无向图
    }
    // ----------最大化最小边----------
    auto widestpath = [&](int source) -> vector <long long>
    {
        vector <long long> bottleneck(n,NEG_INF);
        // 大根堆，存放 (bottleneck值, 节点)
        priority_queue <pair <long long,int>,vector <pair <long long,int>>,less <pair <long long,int>>> pq;

        bottleneck[source] = INF;
        pq.push({INF,source});
        while(!pq.empty())
        {
            auto [cur,u] = pq.top();
            pq.pop();
            if(cur < bottleneck[u]) continue;
            for(const auto& v : adj[u])
            {
                long long newbottleneck = min(cur,v.weight);
                if(newbottleneck > bottleneck[v.to])
                {
                    bottleneck[v.to] = newbottleneck;
                    pq.push({newbottleneck,v.to});
                }
            }
        }
        return bottleneck;
    };
    // ----------最小化最大边----------
    auto minimaxpath = [&](int source) -> vector <long long>
    {
        vector <long long> bottleneck(n,INF);
        // 小根堆，存放 (bottleneck值, 节点)
        priority_queue <pair <long long,int>,vector <pair <long long,int>>,greater <pair <long long,int>>> pq;
        bottleneck[source] = NEG_INF;
        pq.push({NEG_INF,source});
        while(!pq.empty())
        {
            auto [cur,u] = pq.top();
            pq.pop();
            if(cur > bottleneck[u]) continue;
            for(const auto& v : adj[u])
            {
                long long newbottleneck = max(cur,v.weight);
                if(newbottleneck < bottleneck[v.to])
                {
                    bottleneck[v.to] = newbottleneck;
                    pq.push({newbottleneck,v.to});
                }
            }
        }
        return bottleneck;
    };
    return 0;
}
