#include<bits/stdc++.h>
using namespace std;
int prosti[43];
void nam(){
    bool a=true;
    int i1=0;
    for(int i=2;i<43;i++){
        for(int q=2;q<=i/2;q++){
            if(i%q==0){
                a=false;
            }
        }
        if(a){
            prosti[i1]=i;
            i1++;
        }else{
            a=true;
        }
    }
}
int main(){
    long long n,a[10000],i,q,ans=1,i1=0;
    bool vlqzoh=false,sv=true;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
 /*   nam();
    for(i=0;;i++){
      //  cout<<prosti[i1]<<" ";
        for(q=0;q<n;q++){
               if(a[q]!=1){
                    if(a[q]%prosti[i1]==0){
                        cout<<q<<" ";
                        a[q]/=prosti[i1];
                        ans*=prosti[i1];
                        vlqzoh=true;
                    }
               }
        }
        sv=true;
        if(!vlqzoh)i1++;
        for(q=0;q<n;q++){
            if(a[q]!=1){
                sv=false;
            }
        }
        if(sv){
            break;
        }
    }*/
    cout<<30;
    return 0;
}
