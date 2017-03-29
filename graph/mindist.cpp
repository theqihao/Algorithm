#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <stdio.h>
#define INF 0x7fffffff
#define N 505

using namespace std;


struct Node{
    int time;
    int score;
    int local;

    Node() {
        time = 0;
        score = 0;
        local = 0;
    }

    Node(int _time, int _score, int _local) {
        time = _time;
        score = _score;
        local = _local;
    }

    bool operator < (const Node &b) const {
        if (b.time != time) {
            return time > b.time;
        } else {
            return score < b.score;
        }
    }
    bool operator > (const Node &b) const {
        if (b.time != time) {
            return time < b.time;
        } else {
            return score > b.score;
        }
    }
};

struct edge{
    int to;
    int time;
};

int n, m, s, e;
int scores[N];
bool vis[N];
vector<edge> G[N];
int d[N];
int sc[N];
int pre[N];


void add_edge(int x, int y, int z) {
    edge e;
    e.to = y;
    e.time = z;
    G[x].push_back(e);
    e.to = x;
    G[y].push_back(e);
}

int main()
{
   // freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }
    memset(G, 0, sizeof(0));
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add_edge(x, y, z);
    }
    int time = 0;
    int score = 0;

    fill(d, d+n+1, INF);
    memset(pre, -1, sizeof(pre));
    priority_queue<Node> q;
    d[s] = 0;
    sc[s] = scores[s];
    q.push(Node(0, scores[s], s));
    while(!q.empty()) {
        Node now = q.top();
        q.pop();
        int v = now.local;
        if (now.local == e) {
            time = now.time;
            score = now.score;
            break;
        }
        if (d[v] < now.time) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > now.time + e.time) {
                d[e.to] = now.time + e.time;
                sc[e.to] = scores[e.to]+now.score;
                q.push(Node(d[e.to], sc[e.to], e.to));
                pre[v] = e.to;
            } else if (d[e.to] == now.time + e.time){
                if (scores[e.to]+now.score > sc[e.to]) {
                    d[e.to] = now.time + e.time;
                    sc[e.to] = scores[e.to]+now.score;
                    q.push(Node(d[e.to], sc[e.to], e.to));
                    pre[v] = e.to;
                }
            }
        }
    }
    cout << time << " " << score;
    return 0;
}
