#include<iostream>
using namespace std;
long long broi;
int main(){
long long n,k,dokoe=0;
cin>>n>>k;
for(long long m=1;1;m++){
    if(m<=n){
        if(m==n){
            if(k==1){
                cout<<dokoe+m;
                break;
            }
         broi++;
        }
        dokoe+=m*2-1;
    }
      else{
      if(broi+1==k){
        cout<<dokoe+n;
        break;
      }if(broi+2==k){
        cout<<dokoe+(m*2-n);
        break;
      }
      broi+=2;
      dokoe+=m*2-1;
      }
    }
return 0;
}
