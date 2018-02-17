#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct to4ka{
vector<long long>deca;
long long roditel;
};
struct pravoygylnik{
long long x,y,w1,h1;
};
long long n,lica[11001],w,h,m,a,b,otg[11001];
pravoygylnik pr[11001];
to4ka to4ki[11001];
bool to4kaevyv(long long a1,long long b1,long long nomer){
    return (a1>=pr[nomer].x and a1<=(pr[nomer].x+pr[nomer].w1) and b1>=pr[nomer].y and b1<=(pr[nomer].y+pr[nomer].h1));
}
bool evyv(long long nomer1,long long nomer2){
return (pr[nomer1].x>=pr[nomer2].x and pr[nomer1].y>=pr[nomer2].y and (pr[nomer1].x+pr[nomer1].w1)<=(pr[nomer2].x+pr[nomer2].w1) and (pr[nomer1].y+pr[nomer1].h1)<=(pr[nomer2].y+pr[nomer2].h1));
}
long long kyde(long long ot,long long d0){
//    cout<<ot<<d0;
    long long f=ot;
    bool dali=1;
    while(dali==1){
            //cout<<f<<" "<<d0;
        dali=0;
        for(long long i=0;i<to4ki[f].deca.size();i++){
            if(evyv(d0,to4ki[f].deca[i])==1){
                f=to4ki[f].deca[i];
                dali=1;
                break;
            }
        }
    }
    to4ki[f].deca.push_back(d0);
    to4ki[d0].roditel=f;
return 0;
}
long long proverikyde(long long x,long long y,long long kojpravoygylnik){
long long zape4at=kojpravoygylnik;
bool dali=1;
while(dali){
        //cout<<"tak";
        dali=0;
        for(long long i=0;i<to4ki[zape4at].deca.size();i++){
            if(to4kaevyv(x,y,to4ki[zape4at].deca[i])==1){
                zape4at=to4ki[zape4at].deca[i];
                dali=1;
                break;
            }
        }
}
return lica[zape4at];
}
long long namerilice(long long nomer){
long long lice=pr[nomer].h1*pr[nomer].w1;
    for(long long i=0;i<to4ki[nomer].deca.size();i++){
            lice-=pr[to4ki[nomer].deca[i]].w1*pr[to4ki[nomer].deca[i]].h1;
    }
return lice;
}
bool sravnilica(pravoygylnik a,pravoygylnik b){
    return (a.h1*a.w1)>(b.h1*b.w1);
}
int main(){
//cin.tie(NULL);
ios::sync_with_stdio(false);
cin>>w>>h;
pr[0].x=0;
pr[0].y=0;
pr[0].w1=w;
pr[0].h1=h;
to4ki[0].roditel=-1;
cin>>n;
for(long long i=0;i<n;i++){
    cin>>pr[i+1].x>>pr[i+1].y>>pr[i+1].w1>>pr[i+1].h1;
}
//cout<<"tuk";
sort(pr+1,pr+(n+1),sravnilica);
for(long long i=1;i<(n+1);i++){
    kyde(0,i);
}
for(long long i=0;i<(n+1);i++){
    lica[i]=namerilice(i);
}
//cout<<to4kaevyv(3,5,3);
cin>>m;
for(long long i=0;i<m;i++){
    cin>>a>>b;
    otg[i]=proverikyde(a,b,0);
}
for(long long i=0;i<m;i++){
    cout<<otg[i]<<"\n";
}
return 0;
}
/*
11 7
3
3 2 3 2
8 2 2 3
2 1 5 5
4
4 3
3 5
10 1
9 3
11 7
4
0 0 11 7
3 4 3 1
8 2 2 3
2 1 5 5
5
4 3
3 5
10 1
9 3
2 1
*/
