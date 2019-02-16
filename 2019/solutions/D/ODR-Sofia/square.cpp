#include<bits/stdc++.h>
using namespace std;
long long vhod[10000];
int main(){
    long long n;
    cin>>n;
    for(long long i=0;i<n;i++)cin>>vhod[i];
    bool imaLi=true;
    long long chislo;
    for(chislo=1;true;chislo++){
        for(int i=0;i<n;i++){
            if(chislo%vhod[i]!=0){
                imaLi=false;
                break;
            }
        }
        if(imaLi)break;
    }
    cout<<chislo<<endl;
    return 0;
}
