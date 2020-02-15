#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

int opr(char c){
    int a;
    switch(c){
        case '+':a=0;break;
        case '-':a=3;break;
        case '*':a=1;break;
        case '/':a=2;break;
        case ')':a=4;break;
        case '(':a=5;break;
        case '&':a=6;break;
        default:a=7;break;
    }
    return a;
}
int main(){
    char str[200000], nov[200000];
    int pos[200], mah[100], mh=0, pro[2], a=0, b=0, br=0, vr=0, n=0, m=0, p=0;
    bool f=false, g=false, kr, h[3], d[3];
    cin>>str;
    while(true){
        if(str[n]==')'){
            br++;
        }else if(opr(str[n])==7){
            break;
        }
        n++;
    }
    while(br!=a){
        if(m==0){
            p=0;
        }else{
            p=m-1;
        }
        kr=false;
        b=0;
        m=0;
        for(int i=0;i<n;i++){
            vr=opr(str[i]);
            if(vr<4){
                if(vr==3){
                    h[0]=true;
                }else{
                    h[vr]=true;
                }
            }
            if(vr==4 && b==a){
                vr=opr(str[pos[m-1-b]-1]);
                if(vr==5|| vr==0 || (vr==1 && (h[0]==false&&h[1]==true&&h[2]==false)) || (vr==2 && (h[0]==false&&h[1]==false&&h[2]==true))){
                    vr=opr(str[i+1]);
                    if(n==i+1 || vr==4 || vr==0 || vr==3 || (vr==1 && (h[0]==false&&h[1]==true&&h[2]==false)) || (vr==2 && (h[0]==false&&h[1]==false&&h[2]==true))){
                        kr=true;
                        mah[mh]=pos[m-1-b];
                        mah[mh+1]=i;
                        mh+=2;
                    }
                }
                break;
            }else if(vr==4 && b!=a){
                b++;
            }
            if(vr==5){
                pos[m]=i;
                for(int j=0;j<3;j++){
                    h[j]=false;
                }
                m++;
            }
        }
        a++;
    }
    a=0;
    b=0;
    for(int i=0;i<n;i++){
        f=false;
        for(int j=0;j<=mh-1;j++){
            if(mah[j]==i){
                f=true;
                break;
            }
        }
        if(f==false){
            nov[a]=str[i];
            a++;
        }
    }
    cout<<nov;
    return 0;
}
