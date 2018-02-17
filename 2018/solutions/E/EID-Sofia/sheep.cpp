#include<iostream>
using namespace std;
int main() {
    long long N,L,sledva,kchislo,chislo=1,a,i;
    cin>>N>>L;
    long long l[L],b;
    bool otkrihLi=false,vyzmojno=true;
    for(b=0;b<L;b++){
        cin>>l[b];
    }
    for(i=1;i<=N;i++){
            otkrihLi=false;
        for(;otkrihLi==false;chislo++){
            kchislo=chislo;
            vyzmojno=true;
            for(;vyzmojno==true and kchislo>0;){
                a=kchislo%10;
                for(b=0;a!=l[b] and b<L;){
                    b++;
                }
                if(a==l[b]){
                    vyzmojno=false;
                    otkrihLi=false;
                }else if(a!=l[b]){
                otkrihLi=true;
                vyzmojno=true;
                }
                kchislo=kchislo/10;
            }
        }
        sledva=chislo;
    }
    cout<<sledva-1;
return 0;
}
