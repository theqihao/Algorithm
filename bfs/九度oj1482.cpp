#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <map>
#include <string.h>
#define N 200005

using namespace std;

int n;
string s;
int flag = 0;
int ans = -1;
map<string, int> m;

struct Node {
    string s;
    int num;
    Node(string _s, int _num) {
        s = _s;
        num = _num;
    }
};

void bfs() {
    queue<Node> q;
    q.push(Node(s, 0));

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.s.find("2012") != -1) {
            ans = cur.num;
            break;
        }
        for (int i = 0; i < n-1; i++) {
            string next = cur.s;
            next[i] = cur.s[i+1];
            next[i+1] = cur.s[i];
            if (m[next] == 0) {
                m[next] = 1;
                q.push(Node(next, cur.num+1));
            }
        }
    }
}

int main() {
   // freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) == 1) {
        cin >> s;
        int x1 = 0;
        int x2 = 0;
        int x3 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') x1++;
            if (s[i] == '1') x2++;
            if (s[i] == '2') x3++;
        }
        if (x1 < 1 || x2 < 1 || x3 < 2) {
            cout << "-1" << endl;
            continue;
        }
        ans = 0;
        flag = 0;
        m.clear();
        m[s] = 1;
        bfs();
        cout << ans << endl;
    }
    return 0;
}
