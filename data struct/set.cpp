#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int a[1024];
int b[1024];

void createtree(string s, int c[])
{
	for (int i = 0; i < s.size(); i++) {
        int temp = s[i] - '0';
        for (int j = 1; j <= 1023; ) {
            if (c[j] == -1) {
                c[j] = temp;
                break;
            } else if (c[j] > temp) {
                j = j*2;
            } else {
                j = j*2 + 1;
            }
        }
	}

}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    string s;
    string t;
    while (cin >> n) {
        if (n == 0) break;
        memset(a, -1, sizeof(a));
        cin >> s;
        createtree(s, a);
        while (n--) {
            memset(b, -1, sizeof(b));
            cin >> t;
            createtree(t, b);
            int i;
            for (i = 0; i < 1024; i++) {
                if (a[i] != b[i]) {
                    break;
                }
            }
            if (i == 1024) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
	return 0;
}
