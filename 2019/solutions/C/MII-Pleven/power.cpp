#include <bits/stdc++.h>
using namespace std;

long long n,k,a[10001];
bool fl=true;

int main (){
int i;

    cin>>n>>k;
    for(i=1;i<=n;i++) cin>>a[i];

    long long c=1, b=1;
    while(1){
        for(i=1;i<=k;i++) b=b*c;

        for(i=1;i<=n;i++){
            if(b%a[i]!=0){
                fl=false;
                break;
            }
            else fl=true;
        }
        if(fl==false) {
            c++;
            b=1;
        }
         else
         if (fl==true){
            cout<<c;
            break;
         }
    }

   return 0;
}
/*
4 3
3 4 5 6
 out: 30
*/
