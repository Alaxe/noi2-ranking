#include<iostream>
#include<cstring>
using namespace std;
int m,n,p,q,br=0,l=0;
void ways(int gm,int l,char c)
{if(gm>=n-m) {br++; return;}
ways(gm+p,0,'C');
if(l==0) {l=1;ways(gm-q,1,'M'); l=0;}}
int main(){
    cin>>m>>n>>p>>q;
    ways(p,0,'C');
    cout<<br<<endl;
    system("pause");
    return 0;
}
