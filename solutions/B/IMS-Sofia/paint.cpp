#include<iostream>
#include<algorithm>
using namespace std;

struct otsechki{
    long long x,y,y1,nomer;
    bool kraiLiE,tochkaLiE;
}vertikalni[33033],stek[33033];

bool cmp(otsechki a,otsechki b){
    if(a.x==b.x){
        if(a.y==b.y){
            return a.tochkaLiE<b.tochkaLiE;
        }
        return a.y<b.y;
    }
    return a.x<b.x;
}

long long lice[11011],broi=0;
long long vKoiPravougulnikE(otsechki curr){
    long long i;
    for(i=broi-1;broi>=0;i--){
        if(stek[i].y<=curr.y and stek[i].y1>=curr.y1){
            return stek[i].nomer;
        }
    }
    return 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long dulzina,visochina,rects,i,x,y,w,h,vertBr=0,tochki,otg[11011];
    ///VHOD
    cin>>dulzina>>visochina;
    cin>>rects;
    for(i=0;i<rects;i++){
        cin>>x>>y>>w>>h;
        vertikalni[i].x=x;
        vertikalni[i].y=y;
        vertikalni[i].y1=y+h;
        vertikalni[i].kraiLiE=false;
        vertikalni[i].tochkaLiE=false;
        vertikalni[i].nomer=i+1;
        vertikalni[i+rects].x=x+w;
        vertikalni[i+rects].y=y;
        vertikalni[i+rects].y1=y+h;
        vertikalni[i+rects].kraiLiE=true;
        vertikalni[i+rects].tochkaLiE=false;
        vertikalni[i+rects].nomer=i+1;
    }
    vertikalni[2*rects].x=0;
    vertikalni[2*rects].y=0;
    vertikalni[2*rects].y1=visochina;
    vertikalni[2*rects].kraiLiE=false;
    vertikalni[2*rects].tochkaLiE=false;
    vertikalni[2*rects].nomer=0;
    vertikalni[2*rects+1].x=dulzina;
    vertikalni[2*rects+1].y=0;
    vertikalni[2*rects+1].y1=visochina;
    vertikalni[2*rects+1].kraiLiE=true;
    vertikalni[2*rects+1].tochkaLiE=false;
    vertikalni[2*rects+1].nomer=0;
    vertBr=rects*2+2;
    cin>>tochki;
    for(i=0;i<tochki;i++){
        cin>>x>>y;
        vertikalni[vertBr].x=x;
        vertikalni[vertBr].y=y;
        vertikalni[vertBr].y1=y+1;
        vertikalni[vertBr].nomer=i;
        vertikalni[vertBr].tochkaLiE=true;
        vertBr++;
    }
    sort(vertikalni,vertikalni+vertBr,cmp);
    ///RESHENIEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
    stek[0]=vertikalni[0];
    lice[0]=dulzina*visochina;
    for(i=0;i<vertBr-1;i++){
        if(vertikalni[i].tochkaLiE){
            otg[vertikalni[i].nomer]=vKoiPravougulnikE(vertikalni[i]);
        }else if(vertikalni[i].kraiLiE){
            broi--;
            y=vertikalni[i].y1-vertikalni[i].y;
            x=vertikalni[i].x-stek[broi].x;
            lice[vertikalni[i].nomer]+=x*y;
            long long bla=vKoiPravougulnikE(stek[broi]);
            lice[bla]-=x*y;
        }else{
            stek[broi]=vertikalni[i];
            broi++;
        }
    }
    ///IZHOD
    for(i=0;i<tochki;i++){
        cout<<lice[otg[i]]<<"\n";
    }
    return 0;
}
