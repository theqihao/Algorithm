#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define MAXN 100005  
using namespace std;  
int tian[MAXN];  
int king[MAXN];  
int main()  
{  
    int n;  
    int win;  
    while(cin >> n && n){  
        // init  
        win = 0;  
        memset(tian, 0, sizeof tian);  
        memset(king, 0, sizeof king);  
        for (int i = 0; i < n; i++) {  
            cin >> tian[i];  
        }  
        for (int i = 0; i < n; i++) {  
            cin >> king[i];  
        }  
        sort(king, king+n);  
        sort(tian, tian+n);  
  
        int tian_low = 0;  
        int tian_high = n-1;  
        int king_low = 0;  
        int king_high = n-1;  
        while (tian_low <= tian_high && king_low <= king_high) {  
        /* 
        一、如果a的最慢速度大于b的最慢，则直接a的最慢与b的最慢比赛，赢一场； 
        二、如果a的最慢速度小于b的最慢，则用a的最慢浪费b的最快，输一场； 
        三、如果a的最慢速度等于b的最慢，则： 
        1.如果a的最快速度大于b的最快，则直接a的最快与b的最快进行比赛，赢一场； 
        2.如果b的最快速度小于b的最快，则用a的最慢浪费b的最快，输一场； 
        3.如果a的最快速度等于b的最快，即a与b的最慢与最快分别相等，则： 
        a.如果a的最慢速度小于b的最快，则用a的最慢浪费b的最快，输一场； 
        b.如果a的最慢速度等于b的最快，即a的最慢、a的最快、b的最慢、b的最快相等， 
        说明剩余未比赛的马速度全部相等，直接结束比赛。 
         */  
            if (tian[tian_low] > king[king_low]) {  
                win++;  
                tian_low++;  
                king_low++;  
            } else if (tian[tian_low] < king[king_low]) {  
                win--;  
                tian_low++;  
                king_high--;  
            } else if (tian[tian_low] == king[king_low]) {  
                if (tian[tian_high] > king[king_high]) {  
                    win++;  
                    tian_high--;  
                    king_high--;  
                } else if (tian[tian_high] < king[king_high]) {  
                    win--;  
                    tian_low++;  
                    king_high--;  
                } else {  
                    if (tian[tian_low] < king[king_high]) {  
                        win--;  
                        tian_low++;  
                        king_high--;  
                    } else if (tian[tian_low] == king[king_high]){  
                        break;  
                    }  
                }  
            }  
        }  
        cout << win*200 << endl;  
    }  
    return 0;  
}  