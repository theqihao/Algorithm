/*
Problem Description
Push Box is a classic puzzle game. This game play in a grid, there are five types of block in it, the player, the box, the hole, empty place, and the wall. In every step, player can move up, down, left, or right, if the target place is empty. Moreover, if a box in the target place, and the next place in that direction is empty, player can move to the target place, and then push the box to the next place. Remember, both of the player and boxes can't move out of the grid, or you may assume that there is a wall suround the whole grid. The objective of this game is to push every box to a hole. Now, your problem is to find the strategy to achieve the goal with shortest steps, supposed there are exactly three boxes.
 
Input
The input consists of several test cases. Each test case start with a line containing two number, n, m(1 < n, m ≤ 8), the rows and the columns of grid. Then n lines follow, each contain exact m characters, representing the type of block in it. (for empty place, X for player, * for box, # for wall, @ for hole). Each case contain exactly one X, three *, and three @. The input end with EOF.
 
Output
You have to print the length of shortest strategy in a single line for each case. (-1 if no such strategy)
 
Sample Input
4 4
....
..*@
..*@
.X*@

6 6
...#@.
@..*..
#*##..
..##*#
..X...
.@#...
 
Sample Output
7
11
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
using namespace std;  
#define N 9  
  
struct Node {  
    int x[4];  
    int y[4];  
    int step;  
};  
/// 开始结束Node  
Node s, t;  
int n, m;  
char G[N][N];  
///需要三个箱子和人位置确定才能确定状态  
bool v[N][N][N][N][N][N][N][N];  
  
int dx[4] = {0, 1, 0, -1};  
int dy[4] = {1, 0, -1, 0};  
  
bool check(int x, int y) {  
    return (x >= 0 && x < n && y >= 0 && y < m && G[x][y] != '#');  
}  
  
int bfs() {  
    memset(v, 0, sizeof(v));  
    Node now, next;  
    now = s;  
    now.step = 0;  
    v[now.x[0]][now.y[0]][now.x[1]][now.y[1]][now.x[2]][now.y[2]][now.x[3]][now.y[3]] = 1;  
    queue<Node> q;  
    q.push(now);  
  
    while (q.size()) {  
        now = q.front();  
        q.pop();  
        if (G[now.x[0]][now.y[0]] == '@' && G[now.x[1]][now.y[1]] == '@' && G[now.x[2]][now.y[2]] == '@') {  
            return now.step;  
        }  
        for (int i = 0; i < 4; i++) {  
            next = now;  
            next.x[3] += dx[i];  
            next.y[3] += dy[i];  
            /// 越界碰墙  
            if (check(next.x[3], next.y[3]) == 0) continue;  
            /// 判断人是否走到箱子位子上  
            int flag = 0;  
            for (int j = 0; j < 3; j++) {  
                if (next.x[3] == next.x[j] && next.y[3] == next.y[j]) {  
                    /// 箱子往前移动  
                    next.x[j] += dx[i];  
                    next.y[j] += dy[i];  
                    /// 箱子是否越界或碰墙  
                    if (check(next.x[j], next.y[j]) == 0) {  
                        flag = 1; break;  
                    }  
                    /// 箱子是否移到另一个箱子位置处  
                    for (int k = 0; k < 3; k++) {  
                        if (j != k && next.x[k] == next.x[j] && next.y[k] == next.y[j]) {  
                            flag = 1; break;  
                        }  
                    }  
                }  
            }  
            if (flag) continue;  
            /// 如果这种状态发生过  
            if (v[next.x[0]][next.y[0]][next.x[1]][next.y[1]][next.x[2]][next.y[2]][next.x[3]][next.y[3]] == 1) continue;  
            /// 加入队列  
            v[next.x[0]][next.y[0]][next.x[1]][next.y[1]][next.x[2]][next.y[2]][next.x[3]][next.y[3]] = 1;  
            next.step = now.step+1;  
            q.push(next);  
        }  
    }  
    return -1;  
}  
  
int main() {  
    while (~scanf("%d%d", &n, &m)) {  
        int t = 0;  
        for (int i = 0; i < n; i++) {  
            for (int j = 0; j < m; j++) {  
                cin >> G[i][j];  
                if (G[i][j] == 'X') {  
                    s.x[3] = i; s.y[3] = j;  
                } else if (G[i][j] == '*') {  
                    s.x[t] = i; s.y[t++] = j;  
                }  
            }  
        }  
        cout << bfs() << endl;  
    }  
    return 0;  
}  