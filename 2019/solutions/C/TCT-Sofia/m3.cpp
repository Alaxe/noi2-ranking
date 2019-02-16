#include<bits/stdc++.h>
using namespace std;

long long S, K, a, b, c, d;
long long V;

struct Group{
    long long mV;
    long long V=0;
    bool R[4]={false,false,false,false};
    int Rn=0;
    Group(){}
    Group(long long mV, int R){
        this->mV=mV*10000;
        if(R%2==0){
            this->R[0]=true;
            this->Rn++;
        }
        if(R%3==0){
            this->R[1]=true;
            this->Rn++;
        }
        if(R%5==0){
            this->R[2]=true;
            this->Rn++;
        }
        if(R%7==0){
            this->R[3]=true;
            this->Rn++;
        }
    }
};

string lookGood(long long n){
    string o=to_string(n);
    if(o.size()>3){
        o[2]+=o[3]>='5'?1:0;
        o[3]='\0';
    }
    while(o.size()<3){
        o.push_back('0');
    }
    return o;
}

int main(){
    cin>>S>>K>>a>>b>>c>>d;
    V=K%(4*d);
    int s=(K/(4*d))%4;
    Group groups[7];
    if(s==0){Group groups1[7]={Group(a,2),Group(a,3),Group(2*(c-a),2*3),Group(b,5),Group(b,7),Group(2*(c-b),7*5),Group(4*(d-c),2*3*5*7)};copy(groups1,groups1+7,groups);}
    if(s==1){Group groups1[7]={Group(b,2),Group(a,3),Group(a,5),Group(2*(b-a),3*5),Group(3*(c-b),2*3*5),Group(c,7),Group(4*(d-c),2*3*5*7)};copy(groups1,groups1+7,groups);}
    if(s==2){Group groups1[7]={Group(b,2),Group(b,3),Group(2*(c-b),2*3),Group(a,5),Group(a,7),Group(2*(c-a),5*7),Group(4*(d-c),2*3*5*7)};copy(groups1,groups1+7,groups);}
    if(s==3){Group groups1[7]={Group(c,2),Group(a,3),Group(a,5),Group(2*(b-a),3*5),Group(b,7),Group(3*(c-b),3*5*7),Group(4*(d-c),2*3*5*7)};copy(groups1,groups1+7,groups);}

    V*=10000;

    for(int i=0;i<7;i++){
        if(V>groups[i].mV){
            groups[i].V=groups[i].mV;
            V-=groups[i].mV;
        }else{
            groups[i].V=V;
            break;
        }
        //cout<<i<<' '<<groups[i].V<<endl;
    }
    long long rows[4]={0, 0, 0, 0};
    for(int i=0;i<7;i++){
        for(int j=0;j<4;j++){
            if(groups[i].R[j]){
                rows[j]+=groups[i].V/groups[i].Rn;
            }
        }
    }
    /**
    for(int i=0;i<7;i++){
        cout<<groups[i].V<<' ';
    }
    cout<<endl;
    **/
    for(int i=0;i<4;i++){
        cout<<rows[i]/10000<<'.'<<lookGood(rows[i]%10000)<<' ';
    }
}
/**
Compile me daddy
UwU
**/
