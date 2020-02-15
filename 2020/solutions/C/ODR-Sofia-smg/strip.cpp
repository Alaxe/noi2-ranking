#include<bits/stdc++.h>
using namespace std;
unsigned long long kolkoNa4inaIma(unsigned short int red, unsigned short int kolona){
     if(kolona==3 || kolona==red-2)return (red-1)*(red-2)/2; else{
        if(kolona==2 || kolona==red-1)return red-1; else{
            if(kolona==1 || kolona==red)return 1; else{
                return kolkoNa4inaIma(red-1, kolona-1)+kolkoNa4inaIma(red-1, kolona);
            }
        }
    }
}
int main(){
    unsigned short int n, k;
    cin >> n >> k;
    cout << kolkoNa4inaIma(n, k) << endl;
    return 0;
}
