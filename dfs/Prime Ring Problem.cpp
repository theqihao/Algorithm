/*
Problem Description
A ring is compose of n circles as shown in diagram. Put natural number 1, 2, ..., n into each circle separately, and the sum of numbers in two adjacent circles should be a prime.
Note: the number of first circle should always be 1.
Input
n (0 < n < 20).
Output
The output format is shown as sample below. Each row represents a series of circle numbers in the ring beginning from 1 clockwisely and anticlockwisely. The order of numbers must satisfy the above requirements. Print solutions in lexicographical order.
You are to write a program that completes above process.

Print a blank line after each case.
 
Sample Input
6
8
 
Sample Output
Case 1:
1 4 3 2 5 6
1 6 5 2 3 4

Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
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
#define N 100  
int n;  
int a[30];  
bool v[30];  
  
bool is_prime(int x) {  
    if (x == 2) return true;  
    for (int i = 2; i <= sqrt(x); i++) {  
        if (x % i == 0) {  
            return false;  
        }  
    }  
    return true;  
}  
  
/// 素数表,加快  
int prime[38] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};  
  
void dfs(int k) {  
  
    if (k > n) {  
        if (prime[a[1]+a[k-1]]) {  
            for (int i = 1; i <= n; i++) {  
                if (i != 1) cout << " ";  
                cout << a[i];  
            }  
            cout << endl;  
            return;  
        }  
    }  
    if (a[k] == 0) {  
        for (int i = 2; i <= n; i++) {  
            if (v[i] == 0 && prime[a[k-1]+i]) {  
                v[i] = 1;  
                a[k] = i;  
                dfs(k+1);  
                v[i] = 0;  
                a[k] = 0;  
            }  
        }  
    } else {  
        dfs(k+1);  
    }  
    return;  
}  
  
int main() {  
    int t = 1;  
    while (~scanf("%d", &n)) {  
        //ans = 0;  
        memset(a, 0, sizeof(a));  
        a[1] = 1;  
        memset(v, 0, sizeof(v));  
        v[a[1]] = 1;  
  
        cout << "Case " << t++ << ":" << endl;  
        dfs(1);  
        cout << endl;  
    }  
    return 0;  
}  