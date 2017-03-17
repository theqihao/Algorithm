#include <iomanip>  
#include <cstdio>  
#include <cstring>  
#include <vector>  
#include <iostream>  
#include <string.h>  
#include <algorithm>  
#include <set>  
#include <cmath>  
#define N 10005  
using namespace std;  
typedef long long ll;  
int a[5];  


/*
Problem Description
Ray又对数字的列产生了兴趣：
现有四张卡片，用这四张卡片能排列出很多不同的4位数，要求按从小到大的顺序输出这些4位数。
 
Input
每组数据占一行，代表四张卡片上的数字（0<=数字<=9），如果四张卡片都是0，则输入结束。
 
Output
对每组卡片按从小到大的顺序输出所有能由这四张卡片组成的4位数，千位数字相同的在同一行，同一行中每个四位数间用空格分隔。
每组输出数据间空一行，最后一组数据后面没有空行。
 
Sample Input
1 2 3 4
1 1 2 3
0 1 2 3
0 0 0 0
 
Sample Output
1234 1243 1324 1342 1423 1432
2134 2143 2314 2341 2413 2431
3124 3142 3214 3241 3412 3421
4123 4132 4213 4231 4312 4321

1123 1132 1213 1231 1312 1321
2113 2131 2311
3112 3121 3211

1023 1032 1203 1230 1302 1320
2013 2031 2103 2130 2301 2310
3012 3021 3102 3120 3201 3210
*/
  
int main()  
{  
    int fisrt = 0; //控制最后每个case的中间的那个换行  
    while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {  
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) break;  
        if (fisrt) cout << endl;  
        fisrt = 1;  
  
        int flag = 1; //是否是第一个，第一个不用换行  
        int temp;  
        do {  
            if (a[0] == 0) continue;  
            if (flag) {  
                cout << a[0] << a[1] << a[2] << a[3];  
                flag = 0;  
            } else if (temp == a[0]) { // 一行的结束条件  
                cout << " ";  
                cout << a[0] << a[1] << a[2] << a[3];  
            } else { // 如果a[0]发生变化，说明要另起一行  
                cout << endl;  
                cout << a[0] << a[1] << a[2] << a[3];  
            }  
            temp = a[0];  
        }while(next_permutation(a, a+4));  
        // next_permutation 生成全排列  
        cout << endl;  
    }  
    return 0;  
}  