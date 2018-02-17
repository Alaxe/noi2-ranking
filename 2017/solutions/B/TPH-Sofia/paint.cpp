#include <iostream>
using namespace std;
int main ( ) {
    int w1,h1;
    cin >> w1 >> h1;
    long pole[w1][h1];
    for  (long i = 0; i < w1; i++){
        for (long k = 0; k < h1; k++){
            pole[i][k] = 0;
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x,y,w,h;
        cin >> x >> y >> w >> h;
        for (int k = x; k < x + w; k++){
            for (int j = y; j < y + h; j++){
                pole [k][j] = i;
            }
        }
    }
    int br[n+1];
    for (int i = 0; i < n+1; i++){
        br[i] = 0;
    }
    for  (long i = 0; i < w1; i++){
        for (long k = 0; k < h1; k++){
            br[pole[i][k]] ++;
        }
    }
    int bra;
    cin >> bra;
    int mas[bra];
    for (int i = 0; i < bra; i++){
        int ab, ord;
        cin >> ab >> ord;
        mas[i] = br[pole[ab][ord]];
    }
    for (int i = 0; i < bra; i++){
        cout << mas[i] << endl;
    }
    return 0;
}
