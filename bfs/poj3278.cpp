#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <string.h>
#define N 200005

using namespace std;

int n, k;
bool used[N];

struct Node {
    int local;
    int step;
    Node(int x, int y) : local(0), step(0) {
        local = x;
        step = y;
    }
};

int main() {
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &k)) {
        memset(used, 0, sizeof(used));
        queue<Node> q;
        used[n] = 1;
        q.push(Node(n, 0));
        int ans = 0;
        while (!q.empty()) {
            Node now = q.front();
            q.pop();
            if (now.local == k) {
                ans = now.step;
                break;
            }
            if (now.local > 0 && used[now.local - 1] == 0) {
                used[now.local - 1] = 1;
                q.push(Node(now.local - 1, now.step+1));
            }
            if (now.local <= k && used[now.local + 1] == 0) {
                used[now.local + 1] = 1;
                q.push(Node(now.local + 1, now.step+1));
            }
            if (now.local <= k && used[now.local * 2] == 0) {
                used[now.local * 2] = 1;
                q.push(Node(now.local * 2, now.step+1));
            }
        }
        cout << ans << endl;
    }
}
