#include<iostream>
using namespace std;
int main(){
    long long n;
    long long a = 0;
    long long b = 0;
    long long c = 0;
    long long d = 0;
    long long daliE0 = 0;
    long long najGolqmo = 0;
    long long sborZaSega = 0;
    cin >> n;
    char redica[n + 1];
    for(long long i = 0; i < n; i ++){
        cin >> redica[i];
    }
    for(long long i = 0; i < n; i ++){
        if(redica[i] == 'a'){
            a ++;
        }else{
            if(redica[i] == 'b'){
                b ++;
            }else{
                if(redica[i] == 'c'){
                    c ++;
                }else{
                    if(redica[i] == 'd'){
                        d ++;
                    }
                }
            }
        }
        if(a + b == c + d){
            daliE0 ++;
            sborZaSega = a + b + c + d;
            if(sborZaSega >= najGolqmo){
                najGolqmo = sborZaSega;
            }
        }
    }
    if(daliE0 == 0){
        cout << 0 << endl;
    }else{
        cout << najGolqmo << endl;
    }
    return 0;
}
