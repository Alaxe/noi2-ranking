#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
long long s,k,a,b,c,d,ss,v;
void m3(long long vs,long long w){
    if(vs==1){
        if(w<=a){printf("%.3f 0.000 0.000 0.000",1.0*w); return;}
        if(w<=2*a){printf("%.3f %.3f 0.000 0.000",1.0*a,1.0*(w-a)); return;}
        if(w<=2*c){printf("%.3f %.3f 0.000 0.000",a+1.0*(w-2*a)/2,a+1.0*(w-2*a)/2); return;}
        if(w<=2*c+b){printf("%.3f %.3f %.3f 0.000",1.0*c,1.0*c,1.0*(w-2*c)); return;}
        if(w<=2*c+2*b){printf("%.3f %.3f %.3f %.3f",1.0*c,1.0*c,1.0*b,1.0*(w-2*c-b)); return;}
        if(w<=4*c){printf("%.3f %.3f %.3f %.3f",1.0*c,1.0*c,1.0*(w-2*c)/2,1.0*(w-2*c)/2); return;}
        printf("%.3f %.3f %.3f %.3f",1.0*w/4,1.0*w/4,1.0*w/4,1.0*w/4); return;
    }
    if(vs==2){
        if(w<=b){printf("%.3f 0.000 0.000 0.000",1.0*w); return;}
        if(w<=b+a){printf("%.3f %.3f 0.000 0.000",1.0*b,1.0*(w-b)); return;}
        if(w<=2*a+b){printf("%.3f %.3f %.3f 0.000",1.0*b,1.0*a,1.0*(w-a-b)); return;}
        if(w<=3*b){printf("%.3f %.3f %.3f 0.000",1.0*b,1.0*(w-b)/2,1.0*(w-b)/2); return;}
        if(w<=3*c){printf("%.3f %.3f %.3f 0.000",1.0*w/3,1.0*w/3,1.0*w/3); return;}
        if(w<=4*c){printf("%.3f %.3f %.3f %.3f",1.0*c,1.0*c,1.0*c,1.0*(w-3*c)); return;}
        printf("%.3f %.3f %.3f %.3f",1.0*w/4,1.0*w/4,1.0*w/4,1.0*w/4); return;
    }
    if(vs==3){
           // cout<<w<<endl;
        if(w<=b){printf("%.3f 0.000 0.000 0.000",1.0*w); return;}
        if(w<=2*b){printf("%.3f %.3f 0.000 0.000",1.0*b,1.0*(w-b)); return;}
        if(w<=2*c){printf("%.3f %.3f 0.000 0.000",1.0*w/2,1.0*w/2); return;}
        if(w<=2*c+a){printf("%.3f %.3f %.3f 0.000",1.0*c,1.0*c,1.0*(w-2*c)); return;}
        if(w<=2*c+2*a){printf("%.3f %.3f %.3f %.3f",1.0*c,1.0*c,1.0*a,1.0*(w-2*c-a)); return;}
        if(w<=4*c){printf("%.3f %.3f %.3f %.3f",1.0*c, 1.0*c, 1.0*(w-2*c)/2, 1.0*(w-2*c)/2); return;}
        printf("%.3f %.3f %.3f %.3f",1.0*w/4,1.0*w/4,1.0*w/4,1.0*w/4); return;
    }

    if(vs==4){
        if(w<=c){printf("%.3f 0.000 0.000 0.000",1.0*w); return;}
        if(w<=c+a){printf("%.3f %.3f 0.000 0.000",1.0*c,1.0*(w-c)); return;}
        if(w<=c+2*a){printf("%.3f %.3f %.3f 0.000",1.0*c,1.0*a,1.0*(w-a-c)); return;}
        if(w<=b*2+c){printf("%.3f %.3f %.3f 0.000",1.0*c,1.0*(w-c)/2,1.0*(w-c)/2); return;}
        if(w<=2*b+a+c){printf("%.3f %.3f %.3f %.3f",1.0*c,1.0*b,1.0*b,1.0*(w-2*b-c)); return;}
        if(w<=4*c){printf("%.3f %.3f %.3f %.3f",1.0*c, 1.0*(w-c)/3, 1.0*(w-c)/3, 1.0*(w-c)/3); return;}
        printf("%.3f %.3f %.3f %.3f",1.0*w/4,1.0*w/4,1.0*w/4,1.0*w/4); return;
    }
}
int main(){
cin>>s>>k;
cin>>a>>b>>c>>d;
ss=4*d;
if(k>=ss*s){
    printf("%.3f %.3f %.3f %.3f",1.0*k/(s*4),1.0*k/(s*4),1.0*k/(s*4),1.0*k/(s*4));
    return 0;
}
v=k/ss;
if(k%ss>0)v++;
k%=ss;
v%=4;
if(v==0)v=4;
m3(v,k);
return 0;
}
