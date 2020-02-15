#include<bits/stdc++.h>
using namespace std;
unsigned int poKolkoImaOt[100000], n, m, vhod, a, b, sbor;
int main(){
    cin >> n;
    for(unsigned int i=0; i<n; i++){
        cin >> vhod;
        poKolkoImaOt[vhod]++;
    }
    cin >> m;
    for(unsigned int broq4=0; broq4<m; broq4++){
        cin >> a >> b;
        sbor=0;
        for(unsigned int i=a; i<=b; i++)sbor+=poKolkoImaOt[i];
        cout << sbor << endl;
    }
    return 0;
}
