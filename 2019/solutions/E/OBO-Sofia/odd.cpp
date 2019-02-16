#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,br=0,aa,bb;
    cin>>a>>b;
    aa=sqrt(a);
    bb=sqrt(b);
    if(bb<sqrt(b))bb++;
    if(aa<sqrt(a))aa++;
    if(bb*bb>b){
        cout<<bb-aa<<endl;
    }else{
        cout<<bb-aa+1<<endl;
    }
    return 0;
}
