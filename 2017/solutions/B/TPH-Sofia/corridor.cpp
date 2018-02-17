#include <iostream>
using namespace std;
int main ( ) {
    long w,h;
    cin >> w >> h;
    bool plos[w][h];
    for (long i = 0; i < w; i++){
        for (long k = 0; k < h; k++){
            plos [i][k] = 0;
        }
    }
    int n;
    cin >> n;
    int l1,l2;
    cin >> l1 >> l2;
    for (int i = 0; i < l1; i++){
        for (long k = 0; k < h; k++){
            plos[i][k] = 1;
        }
    }
    int save1 = l1,save2 = l2;
    for (int i = 1;i < n;i++){
        int kor1,kor2;
        cin >> kor1 >> kor2;
        if (save1 == kor1){
            if(save2 < kor2){
                for (long i = l1; i < save1; i++){
                    for (long k = save2; k < kor2; k++){
                        plos[i][k] = 1;
                    }
                }
            } else {
                 for (long i = l1; i < save1; i++){
                    for (long k = kor2; k < save2; k++){
                        plos[i][k] = 1;
                    }
                }
            }
        }
        save1 = kor1;
        save2 = kor2;
    }

    int sum = 0;
    for (long i = 0; i < w; i++){
        for (long k = 0; k < h; k++){
            if (plos[i][k] == 0){
                sum ++;
            }
        }
    }
    cout << sum;
    return 0;
}
