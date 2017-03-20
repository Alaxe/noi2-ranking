#include<iostream>
#include<algorithm>
using namespace std;

struct otsechki{
    long long x,y,y1;
}vertikalni[100024];

bool cmp(otsechki a,otsechki b){
    return a.y<b.y;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long dulzina,visochina,tochki,i,lice,pochisteno=0,lastx,lasty,x,y,vertBr=0,maxY=0;
    cin>>dulzina>>visochina;
    lice=dulzina*visochina;
    cin>>tochki;
    cin>>lastx>>lasty;
    for(i=1;i<tochki;i++){
        cin>>x>>y;
        if(lastx==x){
            vertikalni[vertBr].x=lastx;
            vertikalni[vertBr].y=lasty;
            vertikalni[vertBr].y1=y;
            vertBr++;
        }
        lastx=x;
        lasty=y;
    }
    sort(vertikalni,vertikalni+vertBr,cmp);
    for(i=0;i<vertBr;i++){
        if(vertikalni[i].y1>maxY){
            x=vertikalni[i].x;
            y=vertikalni[i].y1-maxY;
            maxY=vertikalni[i].y1;
            pochisteno=pochisteno+x*y;
        }
    }
    cout<<lice-pochisteno<<"\n";
    return 0;
}
