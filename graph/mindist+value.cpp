#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define INF 0x3fffffff
#define MAX_V 1005
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int V, E, K;
int s, t;

struct edge {
    int to;
    int w;
    int p;
};

int d[MAX_V+1];
int ans[MAX_V];
vector<edge> G[MAX_V];

void dijkstra(int s) {
    priority_queue<pp, vector<pp>, greater<pp> > q;
    fill(d, d+MAX_V, INF);
    fill(ans, ans+MAX_V, INF);
    d[s] = 0;
    ans[s] = 0;
    q.push(pp(0, s));

    while (q.size()) {
        pp p = q.top();
        q.pop();
        int v = p.second;
        int w = p.first;
        if (d[v] < w) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if ((d[e.to] > d[v] + e.w) || (d[e.to] == d[v] + e.w && ans[e.to] > ans[v] + e.p)) {
                d[e.to] = d[v] + e.w;
                ans[e.to] = ans[v] + e.p;
                q.push(pp(d[e.to], e.to));
            }
        }
    }
}
int main(void)
{
    //freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &V, &E))
    {
        if (V == 0&&E ==0) break;
        // init
        for (int i = 0; i < V+1; i++) {
            G[i].clear();
        }
        for (int i = 1; i <= E; i++)
        {
            int u, v;
            edge e;
            scanf("%d%d%d%d", &u, &v, &e.w, &e.p);
            e.to = v;
            G[u].push_back(e);
            e.to = u;
            G[v].push_back(e);
        }
        scanf("%d%d", &s, &t);
        dijkstra(s);
        cout << d[t] << " " << ans[t] << endl;
    }

    return 0;
}
