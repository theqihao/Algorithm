/*
Sample Input
7 1 2 ? 6 ? 3 5 8
? 6 5 2 ? 7 1 ? 4
? ? 8 5 1 3 6 7 2
9 2 4 ? 5 6 ? 3 7
5 ? 6 ? ? ? 2 4 1
1 ? 3 7 2 ? 9 ? 5
? ? 1 9 7 5 4 8 6
6 ? 7 8 3 ? 5 1 9
8 5 9 ? 4 ? ? 2 3
 
Sample Output
7 1 2 4 6 9 3 5 8
3 6 5 2 8 7 1 9 4
4 9 8 5 1 3 6 7 2
9 2 4 1 5 6 8 3 7
5 7 6 3 9 8 2 4 1
1 8 3 7 2 4 9 6 5
2 3 1 9 7 5 4 8 6
6 4 7 8 3 2 5 1 9
8 5 9 6 4 1 7 2 3
*/
#include <iostream>  
#include <sstream>  
#include <string.h>  
#include <cstdio>  
#include <string>  
#include <cctype>  
#include <algorithm>  
#include <vector>  
#include <stack>  
#include <queue>  
#include <set>  
#include <cmath>  
#define PI acos(-1)  
#define ll long long  
#define INF 0x7fffffff  
#define N 100  
  
using namespace std;  
  
struct Node {  
    int x;  
    int y;  
}node[88];  
  
int G[10][10];  
int ok, num;  
  
void print() {  
    for (int i = 0; i < 9; i++) {  
        for (int j = 0; j < 8; j++) {  
            cout << G[i][j] << " ";  
        }  
        cout << G[i][8] << endl;  
    }  
}  
  
bool C(int num, int cur) {  
    for (int i = 0; i < 9; i++) {  
        /// 判断同一列，同一行是否有重复  
        if (G[ node[cur].x ][i] == num || G[i][node[cur].y] == num) {  
            return false;  
        }  
    }  
    int x = node[cur].x / 3 * 3;  
    int y = node[cur].y / 3 * 3;  
    /// 判断这个方格是否有重复  
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < 3; j++) {  
            if (G[x+i][y+j] == num) {  
                return false;  
            }  
        }  
    }  
    return true;  
}  
  
void dfs(int cur) {  
    if (ok == 1) return ;  
    if (cur == num) {  
        ok = 1;  
        print();  
        return ;  
    }  
    for (int i = 1; i <= 9; i++) {  
        // cout << i << endl;  
        if (C(i, cur)) {  
            G[ node[cur].x ][ node[cur].y ] = i;  
            dfs(cur+1);  
            G[ node[cur].x ][ node[cur].y ] = 0;  
        }  
    }  
    return ;  
}  
  
int main() {  
    char c;  
    char ch[2];  
    int T = 0;  
    while (cin >> c) {  
        num = 0;  
        ok = 0;  
        memset(G, 0, sizeof(G));  
        memset(node, 0, sizeof(node));  
        if (c == '?') {  
            G[0][0] = 0;  
            node[num].x = 0;  
            node[num].y = 0;  
            num++;  
        } else {  
            G[0][0] = c - '0';  
        }  
        for (int i = 0; i < 9; i++) {  
            for (int j = 0; j < 9; j++) {  
                if (i == 0 && j == 0) continue;  
                cin >> c;  
                if (c == '?') {  
                    G[i][j] = 0;  
                    node[num].x = i;  
                    node[num].y = j;  
                    num++;  
                } else {  
                    G[i][j] = c - '0';  
                }  
            }  
        }  
        if (T++) cout << endl;  
        dfs(0);  
    }  
    return 0;  
}  