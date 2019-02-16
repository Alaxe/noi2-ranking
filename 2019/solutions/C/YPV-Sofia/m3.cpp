#include<bits/stdc++.h>
using namespace std;
long long sektori,litri;
long long a,b,c,d;
void allFull(){
    int ost=litri-sektori*4*d;
    if(ost==0){
        cout<<d<<"."<<"000\n";
        return ;
    }else{
        double ans=ost/(sektori*4.0);
        ans+=d;
        printf("%.3f ",ans);
        printf("%.3f ",ans);
        printf("%.3f ",ans);
        printf("%.3f\n",ans);
        return ;
    }
}
void A(){
    ///acb
    int ost=litri%(4*d);
    double a1,a2,a3,a4;
    if(ost<=a){
        a1=ost;
        a2=0;
        a3=0;
        a4=0;
    }else if(ost<=c+c){
        if(ost<=a+a){
            a1=a;
            a2=ost-a;
            a3=0;
            a4=0;
        }else if(ost>a+a){
            a1=ost/2.0;
            a2=ost/2.0;
            a3=0;
            a4=0;
        }
    }else if(ost<=c+c+b){
        a1=c;
        a2=c;
        a3=ost-2*c;
        a4=0;
    }else if(ost<=c+c+c+c){
        a1=c;
        a2=c;
        if(ost<=c+c+b+b){
            a3=b;
            a4=ost-c-c-b;
        }else{
            a3=(ost-2*c)/2.0;
            a4=(ost-2*c)/2.0;
        }
    }else{
        a1=ost/4.0;
        a2=ost/4.0;
        a3=ost/4.0;
        a4=ost/4.0;
    }
    printf("%.4f ",a1);
    printf("%.4f ",a2);
    printf("%.4f ",a3);
    printf("%.4f\n",a4);
}
void B(){
    ///bac
    int ost=litri%(4*d);
    double a1,a2,a3,a4;
    if(ost<=b){
        a1=ost;
        a2=0;
        a3=0;
        a4=0;
    }else if(ost<=a+b){
        a1=b;
        a2=ost-b;
        a3=0;
        a4=0;
    }else if(ost<=c+c+c){
        if(ost<=b+2*a){
            a1=b;
            a2=a;
            a3=ost-a-b;
            a4=0;
        }else if(ost<=3*b){
            a1=b;
            a2=(ost-b)/2.0;
            a3=(ost-b)/2.0;
            a4=0;
        }else if(ost<=3*c){
            a1=ost/3.0;
            a2=ost/3.0;
            a3=ost/3.0;
            a4=0;
        }
    }else if(ost<=c+c+c+c){
        a1=c;
        a2=c;
        a3=c;
        a4=ost-c;
    }else{
        a1=ost/4.0;
        a2=ost/4.0;
        a3=ost/4.0;
        a4=ost/4.0;
    }
    printf("%.4f ",a1);
    printf("%.4f ",a2);
    printf("%.4f ",a3);
    printf("%.4f\n",a4);
}
void C(){
    ///bca
    int ost=litri%(4*d);
    double a1,a2,a3,a4;
    if(ost<=b){
        a1=ost;
        a2=0;
        a3=0;
        a4=0;
    }else if(ost<=c+c){
        a3=0;
        a4=0;
        if(ost<=2*b){
            a1=b;
            a2=ost=b;
        }else{
            a1=ost/2.0;
            a2=ost/2.0;
        }
    }else if(ost<=c+c+a){
        a1=c;
        a2=c;
        a3=ost-2*c;
        a4=0;
    }else if(ost<=c+c+c+c){
        a1=c;
        a2=c;
        if(ost<=2*(a+c)){
            a3=a;
            a4=ost-a-c-c;
        }else{
            a3=(ost-2*c)/2.0;
            a4=(ost-2*c)/2.0;
        }
    }else{
        a1=ost/4.0;
        a2=ost/4.0;
        a3=ost/4.0;
        a4=ost/4.0;
    }
    printf("%.4f ",a1);
    printf("%.4f ",a2);
    printf("%.4f ",a3);
    printf("%.4f\n",a4);
}
void D(){
    ///cab
    int ost=litri%(4*d);
    double a1,a2,a3,a4;
    if(ost<=c){
        a1=ost;
        a2=0;
        a3=0;
        a4=0;
    }else if(ost<=c+a){
        a1=c;
        a2=ost-c;
        a3=0;
        a4=0;
    }else if(ost<=c+b+b){
        a4=0;
        if(ost<=c+a+a){
            a1=c;
            a2=a;
            a3=ost-a-c;
        }else{
            a1=c;
            a2=(ost-c)/2.0;
            a3=(ost-c)/2.0;
        }
    }else if(ost<=c+c+c+c){
        a1=c;
        if(ost<=c+b+b+b){
            a2=b;
            a3=b;
            a4=ost-b-b-c;
        }else{
            a2=(ost-c)/3.0;
            a3=(ost-c)/3.0;
            a4=(ost-c)/3.0;
        }
    }else{
        a1=ost/4.0;
        a2=ost/4.0;
        a3=ost/4.0;
        a4=ost/4.0;
    }
    printf("%.4f ",a1);
    printf("%.4f ",a2);
    printf("%.4f ",a3);
    printf("%.4f\n",a4);
}
int main(){
    ///ÌÂÍ:
    ///double d=1;
    ///printf("%.4f",d);
    cin>>sektori>>litri;
    cin>>a>>b>>c>>d;
    long long sektorLitri=4*d;
    if(sektorLitri*sektori<=litri){
        allFull();
    }
    long long sektorNum=litri/sektorLitri;
    if(litri%sektorLitri==0){
        double ans1=sektorLitri/4.0,ans2=sektorLitri/4.0,ans3=sektorLitri/4.0,ans4=sektorLitri/4.0;
        printf("%.4f ",ans1);
        printf("%.4f ",ans2);
        printf("%.4f ",ans3);
        printf("%.4f\n",ans4);
        return 0;
    }
    int type=sektorNum%4;
    if(type==0){
        ///acb
        A();
    }
    if(type==1){
        ///bac
        B();
    }
    if(type==2){
        ///bca
        C();
    }
    if(type==3){
        ///cab
        D();
    }
return 0;
}
