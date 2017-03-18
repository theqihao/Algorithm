/*
统计问题
 
Problem Description
在一无限大的二维平面中，我们做如下假设：
1、  每次只能移动一格；
2、  不能向后走（假设你的目的地是“向上”，那么你可以向左走，可以向右走，也可以向上走，但是不可以向下走）；
3、  走过的格子立即塌陷无法再走第二次；

求走n步不同的方案数（2种走法只要有一步不一样，即被认为是不同的方案）。
 
Input
首先给出一个正整数C，表示有C组测试数据
接下来的C行，每行包含一个整数n (n<=20)，表示要走n步。
 
Output
请编程输出走n步的不同方案总数；
每组的输出占一行。
 
Sample Input
2
1
2
 
Sample Output
3
7
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
#define MV 1005  
#define ME 10005  
#define N 20005  
#define M 0x7fffffff  
using namespace std;  
typedef long long ll;  
int n;  
ll dp[N];  
/**< 
 
设走n步的方案数为f(n)，第n步走的是向上方案数为a(n)，第n步走的是向左或向右方案数为b(n)， 
则f(n)=a(n)+b(n)。因为走过的不可以再走，而且不能走相反方向(可以默认一种方向，我假设的是目标向上)， 
所以：对于第n步向上走没有什么限制(与第n-1步无关)，所以a(n)=a(n-1)+b(n-1)； 
而向左向右就有限制了，当第n-1步是向上走时，此时这一行都没走过，所以向左向右都可以， 
当第n-1步是向左或者向右走时，此时只有一个方向可以走，综上b(n)=2*a(n-1)+b(n-1)。 
经过化简可以得到f(n)=2*f(n-1)+f(n-2)。 
 */  
void init() {  
    dp[0] = 0;  
    dp[1] = 3;  
    dp[2] = 7;  
    for (int i = 3; i <= 20; i++) {  
        dp[i] = 2*dp[i-1] + dp[i-2];  
    }  
}  
  
int main()  
{  
    init();  
    int t;  
    cin >> t;  
    while (t--) {  
        int n;  
        cin >> n;  
        cout << dp[n] << endl;  
    }  
    return 0;  
}  