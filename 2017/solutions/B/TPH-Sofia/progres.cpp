#include <iostream>
using namespace std;
int main ( ) {
    int n;
    cin >> n;
    int red[n],d[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            d[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++){
        cin >> red[i];
    }
    int save = 0;
    for (int j = 0; j < n; j++){
        for (int i = j+1; i < n; i++){
            d[j][i] = red[i] - red[j];
            if (d[j][i] > 0){
                save++;
            }
        }
    }

    for (int j = 0; j < n; j++){
        for (int i = j+1; i < n; i++){
            int k = 0;
            if(d[j][i] > 0){
                int savelast1 = j,savelast2 = i;
                for (int f = j; f < n; f++){
                    for (int p = f + 1; p < n; p++){
                        if (d[f][p] == d[j][i] && red[j] !=  red [f] && red[savelast1] + d[j][i] == red[f]){
                            savelast1 = f;
                            savelast2 = p;
                            k++;
                        }
                    }
                }
                for (int f = k; f > 0; f--){
                    save += f;
                }
            }
        }
    }
    cout << save;
    return 0;
}
