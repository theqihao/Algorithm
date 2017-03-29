#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <stdio.h>
#define INF 0x7fffffff
#define N 1005

using namespace std;

bool x[N];
int dp[N][N];
char c[N][N];

int main()
{
   // freopen("in.txt", "r", stdin);
    string a, b;
    while (cin >> a >> b) {
        memset(x, 0, sizeof(x));
        memset(dp, 0, sizeof(dp));
        string ans = "";
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                if (a[i] == b[j]) {
                    dp[i+1][j+1] = dp[i][j]+1;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        int i = a.size();
        int j = b.size();
        while (dp[i][j]) {
            if (dp[i][j] == dp[i-1][j]) {
                i--;
            } else if (dp[i][j] == dp[i][j-1]) {
                j--;
            } else {
                ans += a[i-1];
                i--;
                j--;
            }
        }
        //cout << dp[a.size()][b.size()] << endl;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;

    }
    return 0;
}
