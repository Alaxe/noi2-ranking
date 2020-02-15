#include <iostream>
#include <utility>
using namespace std;
 int main(){

    int n, w1 , w2 , maxx, mqstow1i, mqstow1y, mqstow2z, mqstow2q;
    cin >> n >> w1 >> w2;

    int k [200];

    for (int i = 0; i < n; i++){ cin >> k[i];}

    for(int z = 0; z < n;z++){
        maxx = k[z];
        int mqsto = - 1;
        for (int y = z + 1; y < n; y++){
            if(maxx < k[y]){maxx = k[y]; mqsto = y;}
        }
        if(mqsto != - 1)swap(k[z] , k[mqsto]);
    }

if(w1 < w2 )swap (w1 , w2);
    if(k[0] < w1)
        if(k[n] > w2)
            for (int i = 0; i < n; i++)
                for (int y = i; y < n; y++)
                    if (k[i] + k[y] == w1){
                        mqstow1i = i;
                        mqstow1y = y;
                        for (int z = 0; z < n; z++)
                            for (int q = z; q < n; q++)
                                if (k[z] + k[q] == w2 && k[mqstow1i] != z && k[mqstow1y] != q){
                                    mqstow2z = z;
                                    mqstow2q = q;
                                    cout << k[mqstow1i] + k[mqstow1y] + k[mqstow2q] + k[mqstow2z];
                                }
                                else if (k[z] + k[q] < w2 && k[mqstow1i] != i && k[mqstow1y] != y && k[mqstow2q] != q && k[mqstow2z] != z){
                                    mqstow2z = z;
                                    mqstow2q = q;
                                    cout << k[mqstow1i] + k[mqstow1y] + k[mqstow2q] + k[mqstow2z];
                                }
                    }
                    else if (k[i] + k[y] < w1 && k[mqstow1i] != i && k[mqstow1y] != y){
                        for (int z = 0; z < n; z++)
                            for (int q = z; q < n; q++)
                                if (k[z] + k[q] == w2 && k[mqstow1i] != z && k[mqstow1y] != q){
                                    mqstow2z = z;
                                    mqstow2q = q;
                                    cout << k[mqstow1i] + k[mqstow1y] + k[mqstow2q] + k[mqstow2z];
                                }
                                else if (k[z] + k[q] < w2 && k[mqstow1i] != i && k[mqstow1y] != y && k[mqstow2q] != q && k[mqstow2z] != z){
                                    mqstow2z = z;
                                    mqstow2q = q;
                                    cout << k[mqstow1i] + k[mqstow1y] + k[mqstow2q] + k[mqstow2z];
                                }
                    }

 return 0;
 }
