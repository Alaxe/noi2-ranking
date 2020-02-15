#include<iostream>
using namespace std;
     long long otg[100000];
int main (){
    long long m,n,a,b,i,p;
    cin>>n;
    long long ch[n];
    for(i=0;i<n;i++){
        cin>>ch[i];
    }
    cin>>m;
    for(i=0;i<m;i++){
        cin>>a>>b;
        for(p=0;p<n;p++){
            if(ch[p]>=a && ch[p]<=b){
                otg[i]++;
            }
        }
    }
    for(i=0;i<m;i++){
        cout<<otg[i]<<"\n";
    }
return 0;
}

