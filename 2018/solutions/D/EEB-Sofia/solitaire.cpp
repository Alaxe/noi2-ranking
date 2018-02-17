#include <bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
int n, f, sbor=0;
cin>>n;
char a[n][2*n];
int b[n][n], segX, segY;
for(int i=0; i<n; i++){
        f=0;
    for(int j=0; j<2*n; j++){
        cin>>a[i][j];
        if(a[i][j]=='A'){
            b[i][f]=1;
        }
        if(a[i][j]=='2'){
            b[i][f]=2;
        }
        if(a[i][j]=='3'){
            b[i][f]=3;
        }
        if(a[i][j]=='4'){
            b[i][f]=4;
        }
        if(a[i][j]=='5'){
            b[i][f]=5;
        }
        if(a[i][j]=='6'){
            b[i][f]=6;
        }
        if(a[i][j]=='7'){
            b[i][f]=7;
        }
        if(a[i][j]=='8'){
            b[i][f]=8;
        }
        if(a[i][j]=='9'){
            b[i][f]=9;
        }
        if(a[i][j]=='T'){
            b[i][f]=10;
        }
        if(a[i][j]=='J'){
            b[i][f]=11;
        }
        if(a[i][j]=='Q'){
            b[i][f]=12;
        }
        if(a[i][j]=='K'){
            b[i][f]=13;
        }
        if(j%2==0){
            f++;
        }
    }
}
sbor=b[n-1][0];
segX=0;
segY=n-1;
while(segY!=0 && segX!=n-1){
    if(segY!=0 && segX!=n-1){
        if(b[segY-1][segX]>b[segY][segX+1]){
            segY--;
        }else{
            segX++;
        }
    }else{
        if(segX==n-1 && segY!=0){
            segY--;
        }else{
            if(segX!=n-1 && segY==0){
                segX++;
            }
        }
    }
    sbor=sbor+b[segY][segX];
}
cout<<sbor+b[0][n-1]<<endl;
return 0;
}
