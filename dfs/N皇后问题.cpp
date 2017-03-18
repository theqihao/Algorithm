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
#define N 100  
int a[15];  
int n;  
int num;  
int ans[15] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724};  
  
bool C(int a[], int n) {  
    /// 减少循环次数  
    for (int i = 2; i <= n; i++) {  
        for (int j = 1; j <= i-1; j++) {  
            /// 已经确保i != j,即不在同行  
            if ((a[i] == a[j]) || (abs(a[i] - a[j]) == abs(i-j)))  
                return false;  
        }  
    }  
    return true;  
}  
  
void slove(int k) {  
    if (k > n) {  
        num++;  
    } else {  
        for (int i = 1; i <= n; i++) {  
            /// [2,4,1,3] 表示第一行的棋子摆在第2列；第二行的棋子摆在第4列  
            a[k] = i;  
            if (C(a, k)) {  
                /// 放下一个皇后  
                slove(k+1);  
            }  
        }  
    }  
    return ;  
}  
  
int main() {  
    while (scanf("%d", &n) && n != 0) {  
        //cout <<  ans[n] << endl;  
        num = 0;  
        slove(1);  
        cout << num << endl;  
    }  
    return 0;  
}   