#include <iostream>
using namespace std;
int main(){
    int n,m,br=0;
    cin>>n>>m;
    while(1==1){
        if(n==n/1000*1000+n/100%10*100+n/10%100*10+n%10){
            n=n+n/1000+n/100%10+n/10%100+n%10;
            br++;
            cout<<n<<endl;
        if((n==n/1000*1000+n/100%10*100+n/10%100*10+n%10)&&(n%10==9)){
            n=n+n/1000+n/100%10+n/10%100+n%10;
            br++;
            cout<<n<<endl;
        }      }

            if(n==n/100*100+n/10%10*10+n%10){
                n=n+n/100+n/10%10+n%10;
                br++;
                cout<<n<<endl;
            }
            if((n==n/100*100+n/10%10*10+n%10)&&(n%10==9)){
                n=n+n/100+n/10%10+n%10;
                br++;
                cout<<n<<endl;
            }
            if(n==n/10*10+n%10){
                n=n+n/10+n%10;
                br++;
                cout<<n<<endl;
            }
            if((n==n/10*10+n%10)&&(n%10==9)){
                n=n+n/10+n%10;
                br++;
                cout<<n<<endl;
            }
                if(n==n){
                    n=n+n;
                    br++;
                }
                if((n==n)&&(n==9)){
                    n=n+n;
                    br++;
                }
                if(n>m){
                    cout<<br<<endl;
                    return 0;
                }
    }
}
