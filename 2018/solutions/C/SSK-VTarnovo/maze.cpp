#include<iostream>
using namespace std;
int m,n,br=0,bpsi,bpsj,epsi,epsj,bopsi,bopsj,bombs=1,disttoe,disti,distj,stdisttoe;
char mz[101][101];
int main()
{
cin>>m>>n;
for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>mz[i][j];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        if(mz[i][j]=='B'){bpsi=i;bpsj=j;break;}
    }
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        if(mz[i][j]=='E'){epsi=i;epsj=j;break;}
    }
    bopsi=bpsi;
    bopsj=bpsj;
        if(epsi<bopsi)disti=(epsi-bopsi)-(epsi-bopsi)*2;
        else disti=epsi-bopsi;
            if(epsj<bopsj)distj=(epsj-bopsj)-(epsj-bopsj)*2;
            else distj=epsj-bopsj;
     disttoe=disti+distj;
     stdisttoe=disttoe;
     while(bopsi!=epsi&&bopsj!=epsj)
     {
            if(mz[bopsi][bopsj-1]=='.'){
            bopsj=bopsj-1;
            if(epsj<bopsj)distj=(epsj-bopsj)-(epsj-bopsj)*2;
            else distj=epsj-bopsj;
            disttoe=disti+distj;
            if(stdisttoe<disttoe)bopsj=bopsj+1;
            else br=br+1;}
            //------
            if(mz[bopsi][bopsj+1]=='.'){
            bopsj=bopsj+1;
            if(epsj<bopsj)distj=(epsj-bopsj)-(epsj-bopsj)*2;
            else distj=epsj-bopsj;
            disttoe=disti+distj;
            if(stdisttoe<disttoe)bopsj=bopsj-1;
            else br=br+1;}
            //------
            if(mz[bopsi-1][bopsj]=='.'){
            bopsi=bopsi-1;
            if(epsi<bopsi)disti=(epsi-bopsi)-(epsi-bopsi)*2;
            else disti=epsi-bopsi;
            disttoe=disti+distj;
            if(stdisttoe<disttoe)bopsi=bopsi+1;
            else br=br+1;}
            //------
            if(mz[bopsi+1][bopsj]=='.'){
            bopsi=bopsi+1;
            if(epsi<bopsi)disti=(epsi-bopsi)-(epsi-bopsi)*2;
            else disti=epsi-bopsi;
            disttoe=disti+distj;
            if(stdisttoe<disttoe)bopsj=bopsj-1;
            else br=br+1;}
            ///-----
            if(bombs=1)
            {
            if(mz[bopsi][bopsj-1]=='#'){
            bopsj=bopsj-1;
            if(epsj<bopsj)distj=(epsj-bopsj)-(epsj-bopsj)*2;
            else distj=epsj-bopsj;
            disttoe=disti+distj;
            if(stdisttoe<disttoe)bopsj=bopsj+1;
            else {br=br+3;bombs=0;}
            }
            //------
            if(mz[bopsi][bopsj+1]=='#'){
            bopsj=bopsj+1;
            if(epsj<bopsj)distj=(epsj-bopsj)-(epsj-bopsj)*2;
            else distj=epsj-bopsj;
            disttoe=disti+distj;
            if(stdisttoe<disttoe)bopsj=bopsj-1;
            else {br=br+3;bombs=0;}
            }
            //------
            if(mz[bopsi-1][bopsj]=='#'){
            bopsi=bopsi-1;
            if(epsi<bopsi)disti=(epsi-bopsi)-(epsi-bopsi)*2;
            else disti=epsi-bopsi;
            disttoe=disti+distj;
            if(stdisttoe<disttoe)bopsi=bopsi+1;
            else {br=br+3;bombs=0;}
            }
            //------
            if(mz[bopsi+1][bopsj]=='#'){
            bopsi=bopsi+1;
            if(epsi<bopsi)disti=(epsi-bopsi)-(epsi-bopsi)*2;
            else disti=epsi-bopsi;
            disttoe=disti+distj;
            if(stdisttoe<disttoe)bopsj=bopsj-1;
            else {br=br+3;bombs=0;}
            }
            }
     }
            cout<<br<<endl;
return 0;
}
