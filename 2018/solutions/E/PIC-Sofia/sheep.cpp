#include<iostream>
using namespace std;
int main(){
long long N,L,naiG=0,c;
cin>>N;
cin>>L;
if(1<=N<=10000000 and 1<=L<=3){
long long lipsvat[L],chastOtChislo[8];
for(int i=0;i<L;i++)
    {
    cin>>lipsvat[i];
    }
for(c=1;c<=N;c++)
    {
    for(int COC=0;c>0;COC++)
        {
        chastOtChislo[COC]=c%10;
        c=c/10;
        for(int p=0;p<L;p++)
            {
            if(chastOtChislo[COC]==lipsvat[p])
                {
                break;
                }else
                {
                naiG=c;
                }
            }
        }
    }
cout<<naiG;
}


return 0;
}
