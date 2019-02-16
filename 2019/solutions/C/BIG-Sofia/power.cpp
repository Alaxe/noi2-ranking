#include<iostream>
using namespace std;
unsigned long long n, k, b, counter, coun[13];
bool a[44];
unsigned long long c, gg;
//long long dg;
unsigned long long p[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    gg = 1;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> b;
        if(a[b]){
            continue;
        }
        a[b] = true;
        for(int l = 0; l < 13 && b > 1; l++){
            counter = 0;
            while(b%p[l] == 0){
                counter++;
                b /= p[l];
            }
            if(counter > coun[l]){
                coun[l] = counter;
            }
        }
    }
    //dg = 2;
    for(int i = 0; i < 13; i++){
        if(coun[i] > 0){
            gg *= p[i];
        }
        while(coun[i] > k){
            coun[i] += coun[i]%2;
            coun[i] /= 2;
            gg *= p[i];
        }

    }
    cout << gg << endl;

    //while(dg != gg){

    //}
return 0;
}
/*
44 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42
2 4
109530094869795600

*/

