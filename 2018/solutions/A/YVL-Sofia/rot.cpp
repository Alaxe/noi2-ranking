#include<iostream>
using namespace std;
string s;
string a[10];
void obraboti(int koe, int brsma){
    int naum=0;
    char nachalno=koe+'0', nastoyashto=nachalno;
    for(int i=0;i<s.size();i++){
        a[koe]+=nastoyashto-naum-s[s.size()-i-1]+'0';///a[koe] shte e naobratno!!!
        if(a[koe][i]<'0'){
            a[koe][i]+=brsma;
            naum=1;
        }else{
            naum=0;
        }
        nastoyashto=a[koe][i];
        int d=a[koe][i];
    }
    if(naum==1){
        if(nastoyashto>='2'){
            a[koe]+=nastoyashto-1;
        }else{
            if(nastoyashto=='0'){
                a[koe]="";
                return;
            }
        }
    }
    //cout<<"@"<<a[koe]<<" "<<" "<<a[koe][a[koe].size()-1]-'0';
    if(koe!=a[koe][a[koe].size()-1]-'0') a[koe]="";
    for(int i=0;i<=a[koe].size()/2;i++){
        char w=a[koe][i];
        a[koe][i]=a[koe][a[koe].size()-1-i];
        a[koe][a[koe].size()-1-i]=w;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int brsma;
    cin>>brsma;
    for(int i=0;i<4;i++){
        cin>>s;
        a[0]="";
        for(int j=0;j<s.size();j++){
            if(!(s[j]>='0'&&s[j]<='9')) s[j]=s[j]-'A'+'0';
        }
        for(int k=1;k<10;k++){
            a[k]="";
            obraboti(k, brsma);
            for(int l=0;l<a[k].size();l++){
                if(!(a[k][l]>='0' && a[k][l]<='9')){
                    a[k][l]=a[k][l]-'0'+'A';
                }
            }
            if(a[k].size()>0){
                if(a[0].size()==0){
                    a[0]=a[k];
                }else{
                    if(a[0].size()<a[k].size()){

                    }else{
                        if(a[0].size()==a[k].size()){
                            if(a[0]>a[k]) a[0]=a[k];
                        }else{
                            if(a[0].size()>a[k].size()){
                                a[0]=a[k];
                            }
                        }
                    }
                }
            }
        }
    if(a[0].size()>0) cout<<a[0];
    else cout<<"0";
    cout<<"\n";
    }

    return 0;
}
