#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b,a1,b1;
    cin>>n;
    int redica[100001];
    for(int n1=0;n1<n;n1++){
        cin>>redica[n1];
        if(n1!=0){
            for(int n2=n1;n2>0;){
                if(redica[n2]>=redica[n2-1]){break;}
                else{swap(redica[n2],redica[n2-1]);}
                n2--;
            }
        }
    }
    cin>>m;
    int otg[100001];
    for(int m1=0;m1<m;m1++){
        cin>>a>>b;
        a1=0;
        b1=n-1;
        if(redica[0]<a){for(a1=1;redica[a1]<a&&a1<n-1;a1++){}}
        if(redica[n-1]>b){for(b1=n-2;redica[b1]>b&&b1>0;b1--){}}
        otg[m1]=b1-a1+1;
        if(redica[a1]<a){otg[m1]--;}
        else{if(redica[b1]>b){otg[m1]--;}}
    }
    for(int m1=0;m1<m;m1++){cout<<otg[m1]<<'\n';}
    return 0;
}
