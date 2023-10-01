#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(int, char**) {
    int ans = -1;
    int r, c;
    cin >> r >> c;
    vector<vector<int>> A_original(r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            A_original[i].push_back(a);
        }
    }
    for (int bit = 0; bit < (1 << r); bit++) {
        vector<vector<int>> A(r);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                A[i].push_back(A_original[i][j]);
            }
        }
        //s— •Ô‚µ
        for (int i = 0; i < r; i++) {
            if (bit & (1 << i)) {
                for (int j = 0; j < c; j++) {
                    if (A[i][j] == 0) {
                        A[i][j] = 1;
                    }
                    else {
                        A[i][j] = 0;
                    }
                }
            }
        }
        //—ñ— •Ô‚µ
        int temp = 0;
        for (int i = 0; i < c; i++) {
            int white = 0;//A[i]‚É‚ ‚é”’ŠÛ‚Ì”
            int black = 0;//A[i]‚É‚ ‚é•ŠÛ‚Ì”
            for (int j = 0; j < r; j++) {
                if (A[j][i] == 0)white++;
                if (A[j][i] == 1)black++;
            }
            if (black > white) {
                for (int k = 0; k < r; k++) {
                    if (A[k][i] == 0) {
                        A[k][i] = 1;
                    }
                    else {
                        A[k][i] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (A[i][j] == 0)temp++;
            }
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}