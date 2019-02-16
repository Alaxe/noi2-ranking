#include<bits/stdc++.h>
using namespace std;
long long chislaDoToziRed(long long b){
    long long ans=0,o=1;
    for(int i=1;i<b;i++){
        ans+=o;
        o+=2;
    }
    return ans;
}
int main(){
    long long chislo,sresht,red,a,i;
    bool n=false,c=false;
    cin>>chislo>>sresht;
    a=sresht;
    if(a%2==0){
        n=true;
    }else{
        c=true;
    }
    a--;
    for(red=chislo+1;;red++){
            if(a==0 && red==chislo+1){
                red--;
                n=true;
                c=false;
                break;
            }
        a-=2;
        if(a<=0){
            break;
        }
    }
        if(c){
            cout<<chislaDoToziRed(red)+chislo+2<<"\n";
        }else if(n){
            cout<<chislaDoToziRed(red)+chislo<<"\n";
        }
    return 0;
}
