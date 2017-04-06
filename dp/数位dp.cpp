/*
Bomb 
The counter-terrorists found a time bomb in the dust. But this time the terrorists improve on the time bomb. The number sequence of the time bomb counts from 1 to N. If the current number sequence includes the sub-sequence "49", the power of the blast would add one point. 
Now the counter-terrorist knows the number N. They want to know the final points of the power. Can you help them? 
Input
The first line of input consists of an integer T (1 <= T <= 10000), indicating the number of test cases. For each test case, there will be an integer N (1 <= N <= 2^63-1) as the description. 

The input terminates by end of file marker. 
Output
For each test case, output an integer indicating the final points of the power.
Sample Input
3
1
50
500
Sample Output
0
1
15


        
  
Hint
From 1 to 500, the numbers that include the sub-sequence "49" are "49","149","249","349","449","490","491","492","493","494","495","496","497","498","499",
so the answer is 15.
*/


#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define N 0x7fffffff
#define ll __int64

using namespace std;

ll n;
ll dp[32][5];

/*
dp[i][2] 长度为i 含有“49”的个数
dp[i][1] 长度为i  不含有“49”但是高位为“9”的个数
dp[i][0] 长度为i  不含有“49”的个数

数组 a[i] 从低位到高位存储 n 的每一位数字。

dp[i][2]=dp[i-1][2]*10+dp[i-1][1]; //考虑第i位为“4” i-1位为“9”
dp[i][1]=dp[i-1][0];
dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
*/

void init() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= 32; i++) {
        dp[i][2] = 10 * dp[i-1][2] + dp[i-1][1]; // ---49--
        dp[i][1] = dp[i-1][0]; // 9---
        dp[i][0] = 10 * dp[i-1][0] - dp[i-1][1]; // -------
    }
}

int main()
{
    freopen("in.txt", "r", stdin);

    init();
    int t;
    cin >> t;
    while (t--) {
        scanf("%I64d", &n);
        int b[32];
        int index = 0;
        while (n != 0) {
            b[++index] = (n%10);
            n /= 10;
        }
        b[index+1] = 0;
        int pre = 0;
        int flag = 0;
        ll ans = 0;

        for (int i = index; i > 0; i--) {
            ans += b[i] * dp[i-1][2];
            if (flag) ans += b[i] * dp[i-1][0];
            else if (b[i] > 4) ans += dp[i-1][1];
            if (b[i+1] == 4 && b[i] == 9) flag = 1;
        }
        if (flag) ans++; // self
        printf("%I64d\n", ans);
    }
    return 0;
}
