#include<iostream>
using namespace std;
int main(){
    long long n;
    long long nCpy;
    long long nCpy2;
    long long cif;
    long long brcif2 = 0;
    long long brcif = 0;
    long long chisla = 0;
    bool ednakvo = true;
    cin >> n;
    for(long long i = 1; i <= n; i ++){
        brcif = 0;
        brcif2 = 0;
        nCpy = i;
        nCpy2 = i;
        cif = nCpy % 10;
        //brcif ++;
        while(nCpy2 > 0 ){
            nCpy2 /= 10;
            brcif2 ++;
        }
        while(nCpy > 0){
            if(nCpy % 10 == cif){
                //break;
                //cout << i << endl;
                //ednakvo = false;
                brcif ++;
            }
            nCpy /= 10;
        }
        if(brcif2 == brcif){
            chisla ++;
        }
    }
        cout << chisla << endl;
    return 0;
}
