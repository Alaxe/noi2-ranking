#include <iostream>
using namespace std;
int main (){
long long max=0,seg=1,n,starX,starY,razmerX[100000],razmerY[100000];
cin>>n;
for(long long vhod=0;vhod<n;vhod++){
    cin>>razmerX[vhod]>>razmerY[vhod];
    if(vhod!=0 and razmerX[vhod]<=starX and razmerY[vhod]<=starY){
        seg++;
    }
    else{
        if(vhod!=0 and razmerX[vhod]<=starY and razmerY[vhod]<=starX){
            seg++;
            //cout<<seg;
        }else{
            if(vhod!=0){
                seg=1;
            }
        }
    }
    if(max<seg)max=seg;
    starX=razmerX[vhod];
    starY=razmerY[vhod];
}
cout<<max;
return 0;
}
/*
6
3 4 5 3 3 3 2 3 3 2 7 7
*/
