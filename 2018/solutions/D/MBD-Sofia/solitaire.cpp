#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    char k[n][n*2];
    for(int m=0;m<n;m++){
        for(int j=0;j<n*2;j++){
            cin >> k[m][j];
        }
    }
    int sbor=0;
    for(int m=0;m<n-1;m++){
        //cout << "k[m][3*n+1]=" << k[m][3*n+1] << " m=" << m << " 3*n+1=" << 3*n+1 << endl;
        if(k[m][3*n+1]=='A'){
            sbor=sbor+1;
        }else if(k[m][3*n+1]=='2'){
            sbor=sbor+2;
        }else if(k[m][3*n+1]=='3'){
            sbor=sbor+3;
        }else if(k[m][3*n+1]=='4'){
            sbor=sbor+4;
        }else if(k[m][3*n+1]=='5'){
            sbor=sbor+5;
        }else if(k[m][3*n+1]=='6'){
            sbor=sbor+6;
        }else if(k[m][3*n+1]=='7'){
            sbor=sbor+7;
        }else if(k[m][3*n+1]=='8'){
            sbor=sbor+8;
        }else if(k[m][3*n+1]=='9'){
            sbor=sbor+9;
        }else if(k[m][3*n+1]=='T'){
            sbor=sbor+10;
        }else if(k[m][3*n+1]=='J'){
            sbor=sbor+11;
        }else if(k[m][3*n+1]=='Q'){
            sbor=sbor+12;
        }else if(k[m][3*n+1]=='K'){
            sbor=sbor+13;
        }
        cout << "sbor=" << sbor << endl;
    }
    for(int j=0;j<n*2;j=j+2){
        //cout << "k[n-1][j]=" << k[n-1][j] << " j=" << j << " n-1=" << n-1 << endl;
        if(k[n-1][j]=='A'){
            sbor=sbor+1;
        }else if(k[n-1][j]=='2'){
            sbor=sbor+2;
        }else if(k[n-1][j]=='3'){
            sbor=sbor+3;
        }else if(k[n-1][j]=='4'){
            sbor=sbor+4;
        }else if(k[n-1][j]=='5'){
            sbor=sbor+5;
        }else if(k[n-1][j]=='6'){
            sbor=sbor+6;
        }else if(k[n-1][j]=='7'){
            sbor=sbor+7;
        }else if(k[n-1][j]=='8'){
            sbor=sbor+8;
        }else if(k[n-1][j]=='9'){
            sbor=sbor+9;
        }else if(k[n-1][j]=='T'){
            sbor=sbor+10;
        }else if(k[n-1][j]=='J'){
            sbor=sbor+11;
        }else if(k[n-1][j]=='Q'){
            sbor=sbor+12;
        }else if(k[n-1][j]=='K'){
            sbor=sbor+13;
        }
        cout << "sbor=" << sbor << endl;
    }
    cout << sbor << endl;
    return 0;
}
